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
int Partition(SqList &L, int low, int high)
{
    // Perform one pass on subarray r[low..high] of L, return pivot position
    int pivotkey;
    L.r[0] = L.r[low];
    pivotkey = L.r[low].key;
    while (low < high)
    {
        while (low < high && L.r[high].key >= pivotkey)
        {
            --high;
        }
        while (low < high && L.r[low].key <= pivotkey)
        {
            ++low;
        }
        L.r[high] = L.r[low];
    }
    L.r[low] = L.r[0];
    return low;
}
void QSort(SqList &L, int low, int high)
{
    int pivotloc;
    if (low < high)
    {
        pivotloc = Partition(L, low, high);
        QSort(L, low, pivotloc - 1);
        QSort(L, pivotloc + 1, high);
    }
}
void QuickSort(SqList &L)
{
    QSort(L, 1, L.length);
}
void Creat_Sq(SqList &L)
{
    int i, n;
}