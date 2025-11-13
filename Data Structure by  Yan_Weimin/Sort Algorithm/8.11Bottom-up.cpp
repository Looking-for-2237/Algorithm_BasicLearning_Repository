/*
Merge sort can be implemented iteratively, and in the iterative (bottom-up) version,
you only need to allocate one auxiliary array once, and reuse it throughout the entire process.
This avoids repeated allocation during recursion and improves efficiency.
*/
// Bottom-up Merge Sort
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

void MergeSort(SqList &L)
{
    RedType *buffer = new RedType[MAXSIZE + 1]; // One auxiliary array
    int n = L.length;

    // width = size of sublists to merge, doubling each iteration
    for (int width = 1; width < n; width *= 2)
    {
        // Merge pairs of sublists of size "width"
        for (int i = 1; i <= n; i += 2 * width)
        {
            int low = i;
            int mid = min(i + width - 1, n);
            int high = min(i + 2 * width - 1, n);

            if (mid < high) // Only merge if right part exists
                Merge(L.r, buffer, low, mid, high);
            else
            {
                // If right part doesn't exist, just copy the left part
                for (int k = low; k <= high; k++)
                    buffer[k] = L.r[k];
            }
        }

        // Copy merged result back to L.r
        for (int i = 1; i <= n; i++)
            L.r[i] = buffer[i];
    }

    delete[] buffer;
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
/*
When is the "loop version" more recommended?
When the data volume is particularly large (to avoid stack overflow of recursion)
When used for file merge sort / external sorting (sorting of large data sets)
When requiring Stable + O(n log n) + No Recursion
*/