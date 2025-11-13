#include <iostream>
using namespace std;
#define MAXSIZE 20

typedef struct
{
    int key;
    char *otherinfo;
} RedType;

typedef struct
{
    RedType *r;
    int length;
} SqList;

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

    L.length = n;
    for (i = 1; i <= n; i++)
    {
        cin >> L.r[i].key;
    }
}

void Merge(RedType R[], RedType S[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (R[i].key <= R[j].key)
            S[k++] = R[i++];
        else
            S[k++] = R[j++];
    }
    while (i <= mid)
        S[k++] = R[i++];
    while (j <= high)
        S[k++] = R[j++];
}

void MSort(RedType R[], RedType S[], int low, int high)
{
    if (low == high)
        S[low] = R[low];
    else
    {
        int mid = (low + high) / 2;
        RedType *T = new RedType[MAXSIZE + 1]; // temp array
        MSort(R, T, low, mid);
        MSort(R, T, mid + 1, high);
        Merge(T, S, low, mid, high);
        delete[] T;
    }
}

void MergeSort(SqList &L)
{
    RedType *T = new RedType[MAXSIZE + 1];
    MSort(L.r, T, 1, L.length);
    for (int i = 1; i <= L.length; i++) // copy back
        L.r[i] = T[i];
    delete[] T;
}

void show(const SqList &L)
{
    for (int i = 1; i <= L.length; i++)
        cout << L.r[i].key << " ";
    cout << endl;
}

int main()
{
    SqList R;
    R.r = new RedType[MAXSIZE + 1];
    Create_Sq(R);
    MergeSort(R);
    cout << "Sorted result: ";
    show(R);
    delete[] R.r;
    return 0;
}
