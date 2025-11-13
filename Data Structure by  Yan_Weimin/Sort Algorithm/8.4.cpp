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
void BubbleSort(SqList &L)
{
    int m, j, flag;
    ElemType t;
    m = L.length - 1;
    flag = 1;
    while ((m > 0) && (flag == 1))
    {
        flag = 0;
        for (j = 1; j <= m; j++)
        {
            if (L.r[j].key > L.r[j + 1].key)
            {
                flag = 1;
                t = L.r[j];
                L.r[j] = L.r[j + 1];
                L.r[j + 1] = t;
            }
        }
        --m;
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
    BubbleSort(L);
    cout << "Sorted result: " << endl;
    show(L);
}