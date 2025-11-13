#include <iostream>
using namespace std;
#define MVNum 100
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
    int vexnum, arcnum;
} ALGraph;
bool visited[MVNum];
int LocateVex(ALGraph G, VerTexType v)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (G.vertices[i].data == v)
            return i;
    }
    return -1;
}
void CreateUDG(ALGraph &G)
{ // Create an undirected graph G using the adjacency list representation method.
    int i, k;
    cout << "Please enter the total number of vertices and the total number of edges, separated by a space:";
    cin >> G.vexnum >> G.arcnum;
    cout << endl;
    cout << "Enter the name of the vertex,such as 'a'" << endl;
    for (i = 0; i < G.vexnum; ++i)
    {
        cout << "Please enter the name of the " << (i + 1) << "th point:";
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = nullptr;
    }
    cout << endl;
    cout << "Enter the vertices to which the edges are attached,such as 'a b'" << endl;
    for (k = 0; k < G.arcnum; ++k)
    {
        VerTexType v1, v2;
        int i, j;
        cout << "Please enter the vertex to which the " << (k + 1) << "th edge is attached:";
        cin >> v1 >> v2;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        ArcNode *p1 = new ArcNode;
        p1->adjvex = j;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;
        ArcNode *p2 = new ArcNode;
        p2->adjvex = i;
        p2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2;
    }
}
void DFS(ALGraph G, int v)
{
    cout << G.vertices[v].data << " ";
    visited[v] = true;
    ArcNode *p = G.vertices[v].firstarc;
    while (p != NULL)
    {
        int w = p->adjvex;
        if (!visited[w])
        {
            DFS(G, w);
        }
        p = p->nextarc;
    }
}
int main(void)
{
    cout << "*********************Algorithm6.6 Depth-first search traversal of a graph using adjacency list representation***********************" << endl
         << endl;
    ALGraph G;
    CreateUDG(G);
    cout << endl;
    cout << "The undirected connected graph G has been created successfully!" << endl
         << endl;
    cout << "Please enter the starting point for traversing the connected graph:";
    VerTexType c;
    cin >> c;
    int i;
    for (i = 0; i < G.vexnum; ++i)
    {
        if (c == G.vertices[i].data)
            break;
    }
    cout << endl;
    while (i >= G.vexnum)
    {
        cout << "This point does not exist,please re-enter!" << endl;
        cout << "Please enter the starting point for traversing the connected graph:";
        cin >> c;
        for (i = 0; i < G.vexnum; ++i)
        {
            if (c == G.vertices[i].data)
                break;
        }
    }
    cout << "Depth-first search traversal result of the graph:" << endl;
    DFS(G, i);
    cout << endl;
    return 0;
}
