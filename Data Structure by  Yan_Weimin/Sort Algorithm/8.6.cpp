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
void SelectSort(SqList &L)
{
    int i, j, k;
    ElemType t;
    for (i = 1; i < L.length; ++i)
    {
        k = i;
        for (j = i + 1; j <= L.length; ++j)
        {
            if (L.r[j].key < L.r[k].key)
                k = j;
        }
        if (k != i)
        {
            t = L.r[i];
            L.r[i] = L.r[k];
            L.r[k] = t;
        }
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
int main(void)
{
    SqList L;
    L.r = new ElemType[MAXSIZE + 1];
    L.length = 0;
    Create_Sq(L);
    SelectSort(L);
    cout << "Sorted result:" << endl;
    show(L);
    return 0;
}