#include <iostream>
using namespace std;
#define MVNum 100
#define BDNum MVNum *(MVNum - 1)
#define OK 1
#define ERROR 0
typedef char VerTexType;
typedef struct ArcNode
{
    int adjvex;
    int weight;
    struct ArcNode *nextarc;
} ArcNode;
typedef struct VNode
{
    VerTexType data;
    ArcNode *firstarc;
} VNode, AdjList[MVNum];
typedef struct
{
    AdjList vertices;
    AdjList converse_vertices;
    int vexnum, arcnum;
} ALGraph;
typedef struct
{
    int *base;
    int *top;
    int stacksize;
} spStack;
int indegree[MVNum];
int ve[BDNum];
int vl[BDNum];
int topo[MVNum];
spStack S;
void InitStack(spStack &S)
{
    S.base = new int[MVNum];
    if (!S.base)
        exit(1);
    S.top = S.base;
    S.stacksize = MVNum;
}
void Push(spStack &S, int i)
{
    if (S.top - S.base == S.stacksize)
        return;
    *S.top++ = i;
}
void Pop(spStack &S, int &i)
{
    if (S.top == S.base)
        return;
    i = *--S.top;
}
bool StackEmpty(spStack S)
{
    if (S.top == S.base)
        return true;
    return false;
}
int LocateVex(ALGraph G, VerTexType v)
{
    for (int i = 0; i < G.vexnum; ++i)
        if (G.vertices[i].data == v)
            return i;
    return -1;
}
int CreateUDG(ALGraph &G)
{
    int i, k;
    cout << "Please enter total number of vertices and edges separated by space:";
    cin >> G.vexnum >> G.arcnum;
    cout << endl;
    cout << "Enter vertex names,e.g.'a'" << endl;
    for (i = 0; i < G.vexnum; ++i)
    {
        cout << "Please enter name of vertex" << (i + 1) << ":";
        cin >> G.vertices[i].data;
        G.converse_vertices[i].data = G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
        G.converse_vertices[i].firstarc = NULL;
    }
    cout << endl;
    cout << "Enter the vertices for each edge and its weight,e.g.'a b 3'" << endl;
    for (k = 0; k < G.arcnum; ++k)
    {
        VerTexType v1, v2;
        int i, j, w;
        cout << "Please enter the vertices and weight for edge" << (k + 1) << ":";
        cin >> v1 >> v2 >> w;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        ArcNode *p1 = new ArcNode;
        p1->adjvex = j;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;
        p1->weight = w;
        ArcNode *p2 = new ArcNode;
        p2->adjvex = i;
        p2->nextarc = G.converse_vertices[j].firstarc;
        G.converse_vertices[j].firstarc = p2;
        p2->weight = w;
    }
    return OK;
}
void FindInDegree(ALGraph G)
{
    int i, count;
    for (i = 0; i < G.vexnum; i++)
    {
        count = 0;
        ArcNode *p = G.converse_vertices[i].firstarc;
        if (p)
        {
            while (p)
            {
                p = p->nextarc;
                count++;
            }
        }
        indegree[i] = count;
    }
}
int TopologicalOrder(ALGraph G, int topo[])
{
    int i, m;
    FindInDegree(G);
    InitStack(S);
    for (i = 0; i < G.vexnum; ++i)
    {
        if (!indegree[i])
            Push(S, i);
    }
    m = 0;
    while (!StackEmpty(S))
    {
        Pop(S, i);
        topo[m] = i;
        ++m;
        ArcNode *p = G.vertices[i].firstarc;
        while (p)
        {
            int k = p->adjvex;
            --indegree[k];
            if (indegree[k] == 0)
                Push(S, k);
            p = p->nextarc;
        }
    }
    if (m < G.vexnum)
        return ERROR;
    else
        return OK;
}
int CriticalPath(ALGraph G)
{
    int n, i, k, j, e, l;
    if (!TopologicalOrder(G, topo))
        return ERROR;
    n = G.vexnum;
    for (i = 0; i < n; i++)
        ve[i] = 0;
    for (i = 0; i < n; i++)
    {
        k = topo[i];
        ArcNode *p = G.vertices[k].firstarc;
        while (p != NULL)
        {
            j = p->adjvex;
            if (ve[j] < ve[k] + p->weight)
                ve[j] = ve[k] + p->weight;
            p = p->nextarc;
        }
    }
    for (i = 0; i < n; i++)
    {
        vl[i] = ve[n - 1];
    }
    for (i = n - 1; i >= 0; i--)
    {
        k = topo[i];
        ArcNode *p = G.vertices[k].firstarc;
        while (p != NULL)
        {
            j = p->adjvex;
            if (vl[k] > vl[j] - p->weight)
                vl[k] = vl[j] - p->weight;
            p = p->nextarc;
        }
    }
    cout << endl;
    cout << "Critical activity path(s):";
    for (i = 0; i < n; i++)
    {
        ArcNode *p = G.vertices[i].firstarc;
        while (p != NULL)
        {
            j = p->adjvex;
            e = ve[i];
            l = vl[j] - p->weight;
            if (e == l)
                cout << G.vertices[i].data << "-->" << G.vertices[j].data << " ";
            p = p->nextarc;
        }
    }
    return OK;
}
int main()
{
    cout << "************Algorithm 6.13 Critical Path Algorithm****************" << endl
         << endl;
    ALGraph G;
    CreateUDG(G);
    int *topo = new int[G.vexnum];
    cout << endl;
    cout << "Directed graph created successfully!" << endl
         << endl;
    if (!CriticalPath(G))
    {
        cout << "There is a cycle in the network,cannot perform topological sort!" << endl
             << endl;
    }
    cout << endl;
    return OK;
}