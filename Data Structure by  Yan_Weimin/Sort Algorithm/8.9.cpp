// Algorithm 8.9 Heap Sort
#include <iostream>
using namespace std;
#define MAXSIZE 20 // maximum length of the sequential list
typedef struct
{
    int key;
    char *otherinfo;
} ElemType;
// Storage structure of the sequential list
typedef struct
{
    ElemType *r; // base address of storage space
    int length;  // length of the sequential list
} SqList;        // sequential list type

// Use algorithm 8.7 (sifting method) to adjust heap
void HeapAdjust(SqList &L, int s, int m)
{
    // Assume r[s+1..m] is already a heap; adjust r[s..m] to a max-heap with root at r[s]
    ElemType rc;
    int j;
    rc = L.r[s];
    for (j = 2 * s; j <= m; j *= 2)
    { // sift down along the child node with the larger key
        if (j < m && L.r[j].key < L.r[j + 1].key)
            ++j; // j is the index of the child with the larger key
        if (rc.key >= L.r[j].key)
            break; // rc should be placed at position s
        L.r[s] = L.r[j];
        s = j;
    }
    L.r[s] = rc; // insert
}
// HeapAdjust
void Create_Sq(SqList &L)
{
    int i, n;
    cout << "Please enter the number of elements (no more than " << MAXSIZE << "):" << endl;
    cin >> n; // input count
    cout << "Please enter the data to be sorted:\n";
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

// Use algorithm 8.8 to build the initial heap
void CreatHeap(SqList &L)
{
    // Build a max-heap from the unordered sequence L.r[1..n]
    int i, n;
    n = L.length;
    for (i = n / 2; i > 0; --i) // repeatedly call HeapAdjust
        HeapAdjust(L, i, n);
} // CreatHeap

void HeapSort(SqList &L)
{
    // Perform heap sort on sequential list L
    int i;
    ElemType x;
    CreatHeap(L); // build a max-heap from the unordered sequence L.r[1..L.length]
    for (i = L.length; i > 1; --i)
    {
        x = L.r[1]; // swap the heap top with the last record of the current unsorted subarray L.r[1..i]
        L.r[1] = L.r[i];
        L.r[i] = x;
        HeapAdjust(L, 1, i - 1); // readjust L.r[1..i-1] to a max-heap
    } // for
} // HeapSort
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
    HeapSort(L);
    cout << "Sorted result:" << endl;
    show(L);
    return 0;
}