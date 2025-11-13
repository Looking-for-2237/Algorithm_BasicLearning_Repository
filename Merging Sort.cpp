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

void Merge(RedType src[], RedType dest[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (src[i].key <= src[j].key)
            dest[k++] = src[i++];
        else
            dest[k++] = src[j++];
    }

    while (i <= mid)
        dest[k++] = src[i++];
    while (j <= high)
        dest[k++] = src[j++];
}

void MSort(RedType src[], RedType dest[], int low, int high)
{
    if (low == high)
    {
        dest[low] = src[low];
    }
    else
    {
        int mid = (low + high) / 2;

        // Recursive calls: swap src and dest roles
        MSort(dest, src, low, mid);
        MSort(dest, src, mid + 1, high);

        // Merge sorted halves back into dest
        Merge(src, dest, low, mid, high);
    }
}

void MergeSort(SqList &L)
{
    RedType *buffer = new RedType[MAXSIZE + 1]; // Auxiliary array created once

    // Copy the original data into the buffer
    for (int i = 1; i <= L.length; i++)
        buffer[i] = L.r[i];

    // Perform merge sort using double-buffering technique
    MSort(buffer, L.r, 1, L.length);

    delete[] buffer; // Free auxiliary memory
}

void Display(const SqList &L)
{
    for (int i = 1; i <= L.length; i++)
        cout << L.r[i].key << " ";
    cout << endl;
}

int main()
{
    SqList L;
    L.r = new RedType[MAXSIZE + 1];

    cout << "Enter number of elements (<= " << MAXSIZE << "): ";
    cin >> L.length;

    cout << "Enter the elements:\n";
    for (int i = 1; i <= L.length; i++)
        cin >> L.r[i].key;

    MergeSort(L);

    cout << "Sorted result: ";
    Display(L);

    delete[] L.r;
    return 0;
}
