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
void InsertSort(SqList &L)
{
    int i, j;
    for (i = 2; i <= L.length; ++i)
    {
        if (L.r[0].key < L.r[i - 1].key)
        {
            L.r[0] = L.r[i];
            L.r[i] = L.r[i - 1];
            for (j = i - 2; L.r[0].key < L.r[j].key; --j)
            {
                L.r[j + 1] = L.r[j];
            }
            L.r[j + 1] = L.r[0];
        }
    }
}
void Create_Sq(SqList &L)
{
    int i, n;
    cout << "Please enter the number of data items (no more than " << MAXSIZE << ")." << endl;
    cin >> n;
    cout << "Please enter the data to be sorted:\n";
    while (n > MAXSIZE)
    {
        cout << "Number exceeds limit,must not exceed " << MAXSIZE << ", please re-enter" << endl;
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
    {
        cout << L.r[i].key << endl;
    }
}
int main(void)
{
    SqList L;
    L.r = new ElemType[MAXSIZE + 1];
    L.length = 0;
    Create_Sq(L);
    InsertSort(L);
    cout << "Sorted result:" << endl;
    show(L);
    return 0;
}