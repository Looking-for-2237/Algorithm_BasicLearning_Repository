#include <iostream>
#include <cstdlib>
using namespace std;
// 该算法只有在当k<<数组a的大小时，效率才会明显于对整个数组全部排序取前k个的算法
int partition(long long a[], int l, int r)
{
    long long key = a[l];
    int i = l, j = r;
    while (i < j)
    {
        while (i < j && a[j] >= key)
            j--;
        if (i < j)
            a[i++] = a[j];
        while (i < j && a[i] <= key)
            i++;
        if (i < j)
            a[j--] = a[i];
    }
    a[i] = key;
    return i;
}

void arrangeRight(long long a[], int l, int r, int k)
{
    if (l >= r)
        return;
    int pos = partition(a, l, r);
    int rightSize = r - pos + 1;
    if (rightSize == k)
        return;
    else if (rightSize > k)
        arrangeRight(a, pos + 1, r, k);
    else
        arrangeRight(a, l, pos - 1, k - rightSize);
}
