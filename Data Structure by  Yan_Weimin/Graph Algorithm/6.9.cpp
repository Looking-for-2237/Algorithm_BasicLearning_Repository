#include <iostream>
using namespace std;
typedef char VerTexType;
typedef int ArcType;
#define MVNum 100
#define Maxint 32767
typedef struct
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
} AMGraph;
struct
{
    VerTexType Head;
    VerTexType Tail;
    ArcType lowcost;
} Edge[(MVNum * (MVNum - 1)) / 2];
int Vexset[MVNum];
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
    cout << "Please enter total number of vertices and edges,sparated by space:";
    cin >> G.vexnum >> G.arcnum;
    cout << endl;
    cout << "Enter vertex names,e.g.'a'" << endl;
    for (i = 0; i < G.vexnum; ++i)
    {
        cout << "Enter the name of vertex #" << (i + 1) << ":";
        cin >> G.vexs[i];
    }
    cout << endl;
    for (i = 0; i < G.vexnum; ++i)
    {
        for (j = 0; j < G.vexnum; ++j)
        {
            G.arcs[i][j] = Maxint;
        }
    }
    cout << "Enter edges and their weights, e.g.'a b 6'" << endl;
    for (k = 0; k < G.arcnum; ++k)
    {
        VerTexType v1, v2;
        ArcType w;
        cout << "Enter edge #" << (k + 1) << "(two vertices and weight):";
        cin >> v1 >> v2 >> w;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = G.arcs[i][j];
        Edge[k].lowcost = w;
        Edge[k].Head = v1;
        Edge[k].Tail = v2;
    }
}
void Sort(AMGraph G)
{
    int m = G.arcnum - 1;
    int flag = 1;
    while ((m > 0) && flag == 1)
    {
        flag = 0;
        for (int j = 0; j < m; j++)
        {
            if (Edge[j].lowcost > Edge[j + 1].lowcost)
            {
                flag = 1;
                VerTexType temp_Head = Edge[j].Head;
                Edge[j].Head = Edge[j + 1].Head;
                Edge[j + 1].Head = temp_Head;
                VerTexType temp_Tail = Edge[j].Tail;
                Edge[j].Tail = Edge[j + 1].Tail;
                Edge[j + 1].Tail = temp_Tail;
                ArcType temp_lowcost = Edge[j].lowcost;
                Edge[j].lowcost = Edge[j + 1].lowcost;
                Edge[j + 1].lowcost = temp_lowcost;
            }
        }
        --m;
    }
}
void MiniSpanTree_Kruskal(AMGraph G)
{
    int i, j, v1, v2, vs1, vs2;
    Sort(G);
    for (i = 0; i < G.vexnum; ++i)
        Vexset[i] = i;
    for (i = 0; i < G.arcnum; ++i)
    {
        v1 = LocateVex(G, Edge[i].Head);
        v2 = LocateVex(G, Edge[i].Tail);
        vs1 = Vexset[v1];
        vs2 = Vexset[v2];
        if (vs1 != vs2)
        {
            cout << Edge[i].Head << "-->" << Edge[i].Tail << endl;
            for (j = 0; j < G.vexnum; ++j)
            {
                if (Vexset[j] == vs2)
                    Vexset[j] = vs1;
            }
        }
    }
}
int main(void)
{
    cout << "************Alogrithm 6.9 Kruskal's Algorithm**************" << endl
         << endl;
    AMGraph G;
    CreateUDN(G);
    cout << endl;
    cout << "******Undirected Weighted Graph G Created Successfully!******" << endl;
    cout << endl;
    MiniSpanTree_Kruskal(G);
    return 0;
}