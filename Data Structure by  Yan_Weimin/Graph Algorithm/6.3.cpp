#include <iostream>
using namespace std;
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
typedef struct
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
} Graph;
bool visited[MVNum];
int FirstAdjVex(Graph G, int v);
int NextAdjVex(Graph G, int v, int w);
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
    cout << "Please enter the total number of vertices and edges (separated by a space):";
    cin >> G.vexnum >> G.arcnum;
    cout << endl;
    cout << "Enter the names of vertices,e.g.'a':" << endl;
    for (i = 0; i < G.vexnum; ++i)
    {
        cout << "Please enter the name of vertex " << (i + 1) << ":";
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
    cout << "Enter the two vertices connected by each edge,e.g.'a b'" << endl;
    for (k = 0; k < G.arcnum; ++k)
    {
        VerTexType v1, v2;
        cout << "Please enter the two vertices of edge" << (k + 1) << ":";
        cin >> v1 >> v2;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[j][i] = G.arcs[i][j] = 1;
    }
}
void DFS(Graph G, int v)
{
    cout << G.vexs[v] << " ";
    visited[v] = true;
    int w;
    for (w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w))
    {
        if (!visited[w])
            DFS(G, w);
    }
}
int FirstAdjVex(Graph G, int v)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (G.arcs[v][i] == 1)
            return i;
    }
    return -1;
}
int NextAdjVex(Graph G, int v, int w)
{
    for (int i = w + 1; i < G.vexnum; ++i)
    {
        if (G.arcs[v][i] == 1)
            return i;
    }
    return -1;
}
int main(void)
{
    cout << "*************Algorithm 6.3 Recursive Depth-First Search Traversal of a Connected Graph***************" << endl
         << endl;
    Graph G;
    CreateUDN(G);
    cout << endl;
    cout << "Undirected connected graph G has been created!" << endl
         << endl;
    cout << "Please enter the starting vertex for DFS traversal:";
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
        cout << "The vertex does not exist.Please re-enter:";
        cin >> c;
        for (i = 0; i < G.vexnum; ++i)
        {
            if (c == G.vexs[i])
                break;
        }
    }
    for (int k = 0; k < G.vexnum; ++k)
    {
        visited[k] = false;
    }
    cout << "Depth-First Search traversal result:" << endl;
    DFS(G, i);
    cout << endl;
    return 0;
}