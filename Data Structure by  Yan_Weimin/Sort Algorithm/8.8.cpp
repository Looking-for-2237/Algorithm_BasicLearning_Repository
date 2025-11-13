#include <iostream>
using namespace std;
#define MAXSIZE 20
typedef struct
{
    int key;
    char *otherinfo;
} ElemType;
typedef struct
{
    ElemType *r;
    int length;
} SqList;
void HeapAdjust(SqList &L, int s, int m)
{
    ElemType rc;
    int j;
    for (j = 2 * s; j <= m; j *= 2)
    {
        if (j < m && L.r[j].key < L.r[j + 1].key)
            ++j;
        if (rc.key >= L.r[j].key)
            break;
        L.r[s] = L.r[j];
        s = j;
    }
    L.r[s] = rc;
}
void Create_Sq(SqList &L)
{
    int i, n;
    cout << "Please enter the number of elements (no more than " << MAXSIZE << "):" << endl;
    cin >> n; // input count
    cout << "Please enter the data:\n";
    while (n > MAXSIZE)
    {
        cout << "Number exceeds the limit, must not exceed " << MAXSIZE << ", please re-enter" << endl;
        cin >> n;
    }
    for (i = 1; i <= n; i++)
    {
        cin >> L.r[i].key;
        L.length++;
    }
}
void CreatHeap(SqList &L)
{
    // Build a max-heap from the unordered sequence L.r[1..n]
    int i, n;
    n = L.length;
    for (i = n / 2; i > 0; --i) // repeatedly call HeapAdjust
        HeapAdjust(L, i, n);
}
void show(SqList L)
{
    int i;
    for (i = 1; i <= L.length; i++)
        cout << L.r[i].key << endl;
}
int main()
{
    SqList L;
    L.r = new ElemType[MAXSIZE + 1];
    L.length = 0;
    Create_Sq(L);
    CreatHeap(L);
    cout << "Sequence after building the heap:" << endl;
    show(L);
    return 0;
}