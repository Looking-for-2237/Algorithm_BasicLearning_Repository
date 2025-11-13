#include <iostream>
using namespace std;
#define MVNum 100
#define MAXQSIZE 100
typedef char VerTexType;
typedef int ArcType;
bool visited[MVNum];
typedef struct
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
} Graph;
typedef struct
{
    ArcType *base;
    int front;
    int rear;
} sqQueue;
void InitQueue(sqQueue &Q)
{
    Q.base = new ArcType[MAXQSIZE];
    if (!Q.base)
        exit(1);
    Q.front = Q.rear = 0;
}
void EnQueue(sqQueue &Q, ArcType e)
{
    if ((Q.rear + 1) % MAXQSIZE == Q.front)
        return;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
}
bool QueueEmpty(sqQueue Q)
{
    if (Q.rear == Q.front)
        return true;
    return false;
}
void DeQueue(sqQueue &Q, ArcType &u)
{
    u = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
}
int LocateVex(Graph G, VerTexType v)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}
void CreateUDN(Graph &G)
{
    int i, j, k;
    cout << "Please enter total number of vertices and number of edges,separated by space:";
    cin >> G.vexnum >> G.arcnum;
    cout << endl;
    cout << "Enter the names of vertices,e.g.'a'" << endl;
    for (i = 0; i < G.vexnum; ++i)
    {
        cout << "Please enter the name of vertex" << (i + 1) << ":";
        cin >> G.vexs[i];
    }
    cout << endl;
    for (i = 0; i < G.vexnum; ++i)
    {
        for (j = 0; j < G.vexnum; ++j)
        {
            G.arcs[i][j] = 0;
        }
    }
    cout << "Enter the two vertices of each edge,e.g.'a b'" << endl;
    for (k = 0; k < G.arcnum; ++k)
    {
        VerTexType v1, v2;
        cout << "Please enter the vertices for edge" << (k + 1) << ":";
        cin >> v1 >> v2;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j] = 1;
        G.arcs[j][i] = 1;
    }
}
int FirstAdjVex(Graph G, int v)
{
    int i;
    for (i = 0; i < G.vexnum; ++i)
    {
        if (G.arcs[v][i] == 1 && visited[i] == false)
            return i;
    }
    return -1;
}
int NextAdjVex(Graph G, int u, int w)
{
    int i;
    for (i = w; i < G.vexnum; ++i)
    {
        if (G.arcs[u][i] == 1 && visited[i] == false)
            return i;
    }
    return -1;
}
void BFS(Graph G, int v)
{
    sqQueue Q;
    ArcType u;
    ArcType w;
    cout << G.vexs[v] << " ";
    visited[v] = true;
    InitQueue(Q);
    EnQueue(Q, v);
    while (!QueueEmpty(Q))
    {
        DeQueue(Q, u);
        for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w))
        {
            if (!visited[w])
            {
                cout << G.vexs[w] << " ";
                visited[w] = true;
                EnQueue(Q, w);
            }
        }
    }
}
int main(void)
{
    cout << "**********Algorithm 6.7 Breadth-First Search Traversal of a Connected Graph*************" << endl
         << endl;
    Graph G;
    CreateUDN(G);
    cout << endl;
    cout << "Undirected connected graph G created!" << endl
         << endl;
    cout << "Please enter the starting vertex for travalsal:";
    VerTexType c;
    cin >> c;
    int i;
    for (i = 0; i < G.vexnum; ++i)
    {
        if (c == G.vexs[i])
            break;
    }
    cout << endl;
    while (i >= G.vexnum)
    {
        cout << "That vertex does not exist,please re-enter!" << endl;
        cout << "Please enter the starting vertex for traversal:";
        cin >> c;
        for (i = 0; i < G.vexnum; ++i)
        {
            if (c == G.vexs[i])
                break;
        }
    }
    cout << "Breadth-first search traversal result:" << endl;
    BFS(G, i);
    cout << endl;
    return 0;
}