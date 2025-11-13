#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <iomanip>
using namespace std;
#define FALSE 0
#define TRUE 1
#define OK 1
#define m 3
typedef struct BTNode
{
    int keynum;
    BTNode *parent;
    int key[m + 1]; // Key array, index 0 is unused
    BTNode *prt[m + 1];
} BTNode, *BTree;
struct Result
{
    BTNode *pt;
    int i;
    int tag;
};
int Search(BTree T, int key)
{
    BTree p = T;
    int endnum;
    if (p)
    {
        endnum = p->keynum;
    }
    else
    {
        return 0;
    }
    int i = 0;
    if (endnum == 0)
    {
        return i;
    }
    else if (key >= p->key[endnum])
    {
        i = endnum;
        return i;
    }
    else if (key <= p->key[1])
    {
        return i;
    }
    else
    {
        for (i = 1; i < endnum; i++)
        {
            if (p->key[i] <= key && key < p->key[i + 1])
                return i;
        }
    }
    return 0;
}
void Insert(BTree &q, int i, int x, BTree &ap)
{ // Insert x into q node at position i+1
    int j;
    for (j = m - 1; j > i; j--)
    {
        q->key[j + 1] = q->key[j];
    }
    for (j = m; j > i; j--)
    {
        q->prt[j] = q->prt[j - 1];
    }
    q->key[i + 1] = x;
    q->prt[i + 1] = ap;
    q->keynum++;
}
void split(BTree &q, int s, BTree &ap)
{
    int i = 0;
    ap = new BTNode;
    for (i = s + 1; i <= m; i++)
    {
        ap->key[i - s - 1] = q->key[i];
        /*The middle value is stored in ap->key[0],waiting to be propagated back
          to InsertBTree() to find the proper insertion place.*/
        ap->prt[i - s - 1] = q->prt[i];
    }
    if (ap->prt[0])
    {
        for (i = 0; i <= 1; i++)
        {
            ap->prt[i]->parent = ap;
        }
    }
    ap->keynum = (m - s) - 1;
    ap->parent = q->parent;
    q->keynum = q->keynum - (m - s);
}
void NewRoot(BTree &T, BTree q, int x, BTree &ap)
{
    BTree newT = new BTNode;
    newT->key[1] = x;
    newT->prt[0] = T;
    newT->keynum = 1;
    newT->parent = NULL;
    ap->parent = newT;
    T->parent = newT;
    T = newT;
}
int InsertBTree(BTree &T, int K, BTree q, int i)
{ /* K is Key,and we have found the position to insert the Key which is the i-th position
     among the nodes pointed to by q */
    int x = K;
    BTree ap = NULL;
    int finished = FALSE;
    while (q && !finished)
    {
        Insert(q, i, x, ap);
        if (q->keynum < m)
            finished = TRUE;
        else
        {
            int s = m / 2;
            split(q, s, ap);
            x = ap->key[0];
            q = q->parent;
            if (q)
            {
                i = Search(q, x);
            }
        }
    }
    if (!finished)
        NewRoot(T, q, x, ap);
    return OK;
}
Result SearchBTree(BTree &T, int key)
{
    BTree p = T;
    BTree q = NULL;
    int found = FALSE;
    int i = 0;
    while (p && !found)
    {
        i = Search(p, key);
        if (i > 0 && p->key[i] == key)
            found = TRUE;
        else
        {
            q = p; // q is the parent of p
            p = p->prt[i];
        }
    }
    Result result;
    if (found)
    {
        result.pt = p;
        result.i = i;
        result.tag = 1;
        return result;
    }
    else
    {
        result.pt = q;
        result.i = i;
        result.tag = 0;
        return result;
    }
}
void InitialBTree(BTree &T)
{
    T->keynum = 0;
    T->parent = NULL;
    for (int i = 0; i <= m; i++)
    {
        T->key[i] = 0;
        T->prt[i] = NULL;
    }
}

// Print B-tree: BFS, assign ids to nodes and print keys + parent/children ids
void PrintBTree(BTree T)
{
    if (!T)
    {
        cout << "Empty B-tree\n";
        return;
    }
    queue<BTree> q;
    unordered_map<BTree, int> id;
    int nextId = 1;
    q.push(T);
    id[T] = nextId++;
    vector<BTree> order; // remember nodes in visited order
    while (!q.empty())
    {
        BTree cur = q.front();
        q.pop();
        order.push_back(cur);
        for (int i = 0; i <= m; ++i)
        {
            if (cur->prt[i])
            {
                if (id.find(cur->prt[i]) == id.end())
                {
                    id[cur->prt[i]] = nextId++;
                    q.push(cur->prt[i]);
                }
            }
        }
    }
    cout << "B-Tree nodes (level-order):\n";
    for (BTree node : order)
    {
        int nid = id[node];
        cout << "Node " << nid << " : keys = [";
        for (int k = 1; k <= node->keynum; ++k)
        {
            cout << node->key[k];
            if (k < node->keynum)
                cout << ", ";
        }
        cout << "] ";
        if (node->parent)
            cout << " parent=" << id[node->parent];
        else
            cout << " parent=NULL";
        cout << "  children={";
        bool first = true;
        for (int i = 0; i <= m; ++i)
        {
            if (node->prt[i])
            {
                if (!first)
                    cout << ", ";
                cout << id[node->prt[i]];
                first = false;
            }
        }
        cout << "}\n";
    }
}
int main(void)
{
    BTree T = new BTNode;
    InitialBTree(T);
    Result result;
    int a[11] = {45, 24, 53, 90, 3, 12, 50, 61, 70, 100};
    for (int i = 0; i < 10; i++)
    {
        result = SearchBTree(T, a[i]);
        if (result.tag == 0)
        {
            InsertBTree(T, a[i], result.pt, result.i);
        }
    }
    PrintBTree(T);
    cout << "OK\n";
    return 0;
}