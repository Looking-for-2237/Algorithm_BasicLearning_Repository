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
void BInsertSort(SqList &L)
{
    int i, j, low, high, m;
    for (i = 2; i <= L.length; ++i)
    {
        L.r[0] = L.r[i];
        low = 1;
        high = i - 1;
        while (low <= high)
        {
            m = (low + high) / 2;
            if (L.r[0].key < L.r[m].key)
                high = m - 1;
            else
                low = m + 1;
        }
        for (j = i - 1; j >= high + 1; --j)
        {
            L.r[j + 1] = L.r[j];
        }
        L.r[high + 1] = L.r[0];
    }
}
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
void show(SqList L)
{
    int i;
    for (i = 1; i <= L.length; i++)
        cout << L.r[i].key << endl;
}
void main()
{
    SqList L;
    L.r = new ElemType[MAXSIZE + 1];
    L.length = 0;
    Create_Sq(L);
    BInsertSort(L);
    cout << "Sorted result:" << endl;
    show(L);
}