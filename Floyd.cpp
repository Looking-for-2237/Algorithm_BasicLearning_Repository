#include <iostream>
using namespace std;
#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
int Path[MVNum][MVNum];
int D[MVNum][MVNum];
typedef struct
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
} AMGraph;
int LocateVex(AMGraph G, VerTexType v)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}
void CreateUDN(AMGraph &G)
{
    int i, j, k;
    cout << "Enter total number of vertices and edges,sparated by space:";
    cin >> G.vexnum >> G.arcnum;
    cout << endl;
    cout << "Enter vertex names,e.g.'a'" << endl;
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
            if (j != i)
                G.arcs[i][j] = MaxInt;
            else
                G.arcs[i][j] = 0;
        }
    }
    cout << "Enter the vertices and weight for each edge,e.g.'a b 3'" << endl;
    for (k = 0; k < G.arcnum; ++k)
    {
        VerTexType v1, v2;
        ArcType w;
        cout << "Please enter the vertices and weight for edge" << (k + 1) << ":";
        cin >> v1 >> v2 >> w;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j] = w;
    }
}
void ShortestPath_Floyed(AMGraph G)
{
    int i, j, k;
    for (i = 0; i < G.vexnum; ++i)
    {
        for (j = 0; j < G.vexnum; ++j)
        {
            D[i][j] = G.arcs[i][j];
            if (D[i][j] < MaxInt && i != j)
                Path[i][j] = i;
            else
                Path[i][j] = -1;
        }
    }
    for (k = 0; k < G.vexnum; ++k)
    {
        for (i = 0; i < G.vexnum; ++i)
        {
            for (j = 0; j < G.vexnum; ++j)
            {
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    Path[i][j] = Path[k][j];
                }
            }
        }
    }
}
void DisplayPath(AMGraph G, int begin, int temp)
{
    if (Path[begin][temp] != -1)
    {
        DisplayPath(G, begin, Path[begin][temp]);
        cout << G.vexs[Path[begin][temp]] << "-->";
    }
}
int main(void)
{
    cout << "********Algorithm 6.11:Floyd's Algorithm *********" << endl
         << endl;
    AMGraph G;
    char start, destination;
    int num_start, num_destination;
    CreateUDN(G);
    cout << endl;
    cout << "Directed network G created!" << endl;
    ShortestPath_Floyed(G);
    cout << "Please enter the start and end vertex names of the path:";
    cin >> start >> destination;
    num_start = LocateVex(G, start);
    num_destination = LocateVex(G, destination);
    DisplayPath(G, num_start, num_destination);
    cout << G.vexs[num_destination] << endl;
    cout << "Length of the shortest path:" << D[num_start][num_destination] << endl;
    cout << endl;
    return 0;
}