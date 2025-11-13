#include <iostream>
using namespace std;
#define MVNum 100
#define OK 1
#define ERROR 0
typedef char VerTexType;
typedef struct ArcNode
{
    int adjvex;
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
bool StackEmpty(spStack S)
{
    if (S.top == S.base)
        return true;
    return false;
}
void Pop(spStack &S, int &i)
{
    if (S.top == S.base)
        return;
    i = *--S.top;
}
int LocateVex(ALGraph G, VerTexType v)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (G.vertices[i].data == v)
            return i;
    }
    return -1;
}
int CreateUDG(ALGraph &G)
{
    int i, k;
    cout << "Please enter the total number of vertices and edges,separated by space:";
    cin >> G.vexnum >> G.arcnum;
    cout << "Enter vertex names,e.g.'a'" << endl;
    for (i = 0; i < G.vexnum; ++i)
    {
        cout << "Please enter the name of vertex" << (i + 1) << ":";
        cin >> G.vertices[i].data;
        G.converse_vertices[i].data = G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
        G.converse_vertices[i].firstarc = NULL;
    }
    cout << endl;
    cout << "Enter the vertices the edge is attached to,e.g.'a b'" << endl;
    for (k = 0; k < G.arcnum; ++k)
    {
        VerTexType v1, v2;
        int i, j;
        cout << "Please enter the vertices for edge" << (k + 1) << ":";
        cin >> v1 >> v2;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        ArcNode *p1 = new ArcNode;
        p1->adjvex = j;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;
        ArcNode *p2 = new ArcNode;
        p2->adjvex = i;
        p2->nextarc = G.converse_vertices[j].firstarc;
        G.converse_vertices[j].firstarc = p2;
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
int TopologicalSort(ALGraph G, int topo[])
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
int main(void)
{
    cout << "***********Alogrithm 6.12 Topological Sort*************" << endl
         << endl;
    ALGraph G;
    CreateUDG(G);
    int *topo = new int[G.vexnum];
    cout << endl;
    cout << "Adjacency list and reverse adjacency list for the directed graph have been created!" << endl
         << endl;
    if (TopologicalSort(G, topo))
    {
        cout << "The topological order of the directed graph is :";
        for (int j = 0; j < G.vexnum; j++)
        {
            if (j != G.vexnum - 1)
                cout << G.vertices[topo[j]].data << ",";
            else
                cout << G.vertices[topo[j]].data << endl
                     << endl;
        }
    }
    else
        cout << "The graph contains a cycle;topological sorting is not possible!" << endl
             << endl;
    return OK;
}