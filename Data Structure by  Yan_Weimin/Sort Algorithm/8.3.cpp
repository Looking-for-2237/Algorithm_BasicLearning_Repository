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
void ShellInsert(SqList &L, int dk)
{ // Perform one pass of Shell insertion sort on L with increment dk
    int i, j;
    for (i = dk + 1; i <= L.length; ++i)
    {
        if (L.r[i].key < L.r[i - dk].key)
        {
            L.r[0] = L.r[i];
            for (j = i - dk; j > 0 && L.r[0].key < L.r[j].key; j -= dk)
            {
                L.r[j + dk] = L.r[j];
            }
            L.r[j + dk] = L.r[0];
        }
    }
}
void ShellSort(SqList &L, int dt[], int t)
{ // Perform t passes of Shell sort on L using increment sequence dt[0..t-1]
    int k;
    for (k = 0; k < t; ++k)
    {
        ShellInsert(L, dt[k]);
    }
}
void Create_Sq(SqList &L)
{
    int i, n;
    cout << "Please enter the number of elements (no more than " << MAXSIZE << "):" << endl;
    cin >> n;
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
    int i, t;                   // t is the length of the increment array
    int *dt = new int[MAXSIZE]; // increment array
    cout << "Please enter the number of increments:\n";
    cin >> t;
    for (i = 0; i < t; i++)
    {
        cout << "Increment #" << i + 1 << ":\n";
        cin >> dt[i];
    }
    ShellSort(L, dt, t);
    cout << "Sorted result:" << endl;
    show(L);
    return 0;
}