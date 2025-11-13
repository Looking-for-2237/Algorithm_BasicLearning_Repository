#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define MAXNUM_KEY 8
#define RADIX 10
#define MAX_SPACE 10000
typedef char KeysType;
typedef int InfoType;
typedef struct
{
    KeysType keys[MAXNUM_KEY];
    InfoType otheritems;
    int next;
} SLCell;
typedef struct
{
    SLCell r[MAX_SPACE];
    int keynum;
    int recnum;
} SLList;
typedef int ArrType[RADIX];
static void InitList(SLList *L)
{
    char c[MAXNUM_KEY], c1[MAXNUM_KEY];
    int i, j, n, max; // max is the maximum value among all keys
    max = -10000;
    cout << "Enter the number of data elements, no more than " << MAX_SPACE << ".\n";
    cin >> n;
    while (n > MAX_SPACE)
    {
        cout << "The number excceeds the limit.Please re-enter,no more than " << MAX_SPACE << ".\n";
        cin >> n;
    }
    int *D = new int[n];
    cout << "Enter" << n << "integers to sort:\n";
    for (i = 0; i < n; i++)
    {
        cin >> D[i];
        if (max < D[i])
        {
            max = D[i];
        }
    }
    (*L).keynum = (int)(ceil(log10(max)));
    (*L).recnum = n;
    for (i = 1; i <= n; i++)
    {
        _itoa_s(D[i - 1], c, sizeof(c), 10);
        for (j = (int)strlen(c); j < (*L).keynum; j++)
        {
            strcpy_s(c1, sizeof(c1), "0");
            strcat_s(c1, sizeof(c1), c);
            strcpy_s(c, sizeof(c), c1);
        }
        for (j = 0; j < (*L).keynum; j++)
        {
            (*L).r[i].keys[j] = c[(*L).keynum - 1 - j];
        }
    }
}
static int ord(char c)
{
    return c - '0';
}
static void Distribute(SLCell *r, int i, ArrType &f, ArrType &e)
{
    int j, p;
    for (j = 0; j < RADIX; ++j)
    {
        f[j] = 0;
    }
    for (p = r[0].next; p; p = r[p].next)
    {
        j = ord(r[p].keys[i]);
        if (!f[j])
        {
            f[j] = p;
        }
        else
        {
            r[e[j]].next = p;
        }
        e[j] = p;
    }
}
static int succ(int i)
{
    return ++i;
}
static void Collect(SLCell *r, int i, ArrType &f, ArrType &e)
{
    int j, t;
    for (j = 0; !f[j]; j = succ(j))
    {
    };
    r[0].next = f[j];
    t = e[j];
    while (j < RADIX - 1)
    {
        for (j = succ(j); j < RADIX - 1 && !f[j]; j = succ(j))
        {
        };
        if (f[j])
        {
            r[t].next = f[j];
            t = e[j];
        }
    }
    r[t].next = 0;
}
static void RadixSort(SLList &L)
{
    int i;
    ArrType f, e;
    for (i = 0; i < L.recnum; ++i)
    {
        L.r[i].next = i + 1;
    }
    L.r[L.recnum].next = 0;
    for (i = 0; i < L.keynum; ++i)
    {
        Distribute(L.r, i, f, e);
        Collect(L.r, i, f, e);
    }
}
static void newPrint(SLList L)
{
    int i, j;
    for (i = 1; i <= L.recnum; i++)
    {
        for (j = L.keynum - 1; j >= 0; j--)
        {
            cout << L.r[i].keys[j];
        }
        cout << endl;
    }
}
static void Sort(SLList L, int adr[])
{
    int i = 1, p = L.r[0].next;
    while (p)
    {
        adr[i++] = p;
        p = L.r[p].next;
    }
}
static void Rearrange(SLList *L, int adr[])
{ // Rearrange L.r[] in place according to adr
    int i, j, k;
    for (i = 1; i <= (*L).recnum; i++)
    { /* Cycle-Based In-Place Permutation Algorithm */
        if (adr[i] != i)
        {
            j = i;
            (*L).r[0] = (*L).r[i];
            while (adr[j] != i)
            { // Move L.r[adr[j]] into position until adr[j] = i
                k = adr[j];
                (*L).r[j] = (*L).r[k];
                adr[j] = j;
                j = k;
            }
            (*L).r[j] = (*L).r[0];
            adr[j] = j;
        }
    }
}
int main()
{
    SLList l;
    int *adr;
    InitList(&l);
    RadixSort(l);
    adr = new int[l.recnum];
    Sort(l, adr);
    Rearrange(&l, adr);
    cout << "After sorting (records rearranged):\n";
    newPrint(l);
    return 0;
}