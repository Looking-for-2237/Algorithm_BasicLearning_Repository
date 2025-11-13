#include <iostream>
using namespace std;
#define Maxint 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
int *D = new int[MVNum];
bool *S = new bool[MVNum];
int *Path = new int[MVNum];
typedef struct
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vernum, arcnum;
} AMGraph;
int LocateVex(AMGraph G, VerTexType v)
{
    for (int i = 0; i < G.vernum; ++i)
    {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}
void CreateUDN(AMGraph &G)
{
    int i, j, k;
    cout << "Please enter the total number of vertices and edges,separated by a space:";
    cin >> G.vernum >> G.arcnum;
    cout << endl;
    cout << "Enter vertex names(e.g.'a')" << endl;
    for (i = 0; i < G.vernum; ++i)
    {
        cout << "Please enter the name of vertex" << (i + 1) << ":";
        cin >> G.vexs[i];
    }
    cout << endl;
    for (i = 0; i < G.vernum; ++i)
    {
        for (j = 0; j < G.vernum; ++j)
        {
            G.arcs[i][j] = Maxint;
        }
    }
    cout << "Enter the two vertices and weight of each edge,e.g.'a b 7'" << endl;
    for (k = 0; k < G.arcnum; ++k)
    {
        VerTexType v1, v2;
        ArcType w;
        cout << "Please enter the two vertices and weight of edge" << (k + 1) << ":";
        cin >> v1 >> v2 >> w;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = G.arcs[i][j];
    }
}
void ShortPath_DIJ(AMGraph G, int v0)
{
    int v, i, w, min;
    int n = G.vernum;
    for (v = 0; v < n; ++v)
    {
        S[v] = false;
        D[v] = G.arcs[v0][v];
        if (D[v] < Maxint)
            Path[v] = v0;
        else
            Path[v] = -1;
    }
    S[v0] = true;
    D[v0] = 0;
    for (i = 1; i < n; ++i)
    {
        min = Maxint;
        for (w = 0; w < n; ++w)
        {
            if (!S[w] && D[w] < min)
            {
                v = w;
                min = D[w];
            }
        }
        S[v] = true;
        for (w = 0; w < n; ++w)
        {
            if (!S[w] && (D[v] + G.arcs[v][w] < D[w]))
            {
                D[w] = D[v] + G.arcs[v][w];
                Path[w] = v;
            }
        }
    }
}
void DisplayPath(AMGraph G, int begin, int temp)
{
    if (Path[temp] != -1)
    {
        DisplayPath(G, begin, Path[temp]);
        cout << G.vexs[Path[temp]] << "-->";
    }
}
int main(void)
{
    cout << "************Algorithm 6.10 Dijkstra Algorithm**************" << endl
         << endl;
    AMGraph G;
    int i, j, num_start, num_destination;
    VerTexType start, destination;
    CreateUDN(G);
    cout << endl;
    cout << "********Undirected network G created successfully!********" << endl;
    for (i = 0; i < G.vernum; ++i)
    {
        for (j = 0; j < G.vernum; ++j)
        {
            if (j != G.vernum - 1)
            {
                if (G.arcs[i][j] != Maxint)
                    cout << G.arcs[i][j] << "\t";
                else
                    cout << "∞" << "\t";
            }
            else
            {
                if (G.arcs[i][j] != Maxint)
                    cout << G.arcs[i][j] << endl;
                else
                    cout << "∞" << endl;
            }
        }
    }
    cout << endl;
    cout << "Please enter the start and destination vertex names:";
    cin >> start >> destination;
    num_start = LocateVex(G, start);
    num_destination = LocateVex(G, destination);
    ShortPath_DIJ(G, num_start);
    cout << endl
         << "The shortest path is:";
    DisplayPath(G, num_start, num_destination);
    cout << G.vexs[num_destination] << endl;
    return 0;
}
