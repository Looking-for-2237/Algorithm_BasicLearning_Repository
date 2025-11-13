#include <iostream>
#include <vector>
using namespace std;

// 合并两个有序子区间
void merge(vector<int> &arr, int left, int mid, int right, vector<int> &temp)
{
    int i = left;    // 左区间起点
    int j = mid + 1; // 右区间起点
    int k = left;    // 临时数组起点

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    // 将排好序的部分拷贝回原数组
    for (int p = left; p <= right; p++)
    {
        arr[p] = temp[p];
    }
}

// 循环版归并排序
void mergeSort(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp(n);

    // 子数组的长度从 1 开始，每次翻倍
    for (int len = 1; len < n; len *= 2)
    {
        // 以步长 2*len 遍历数组
        for (int left = 0; left < n - len; left += 2 * len)
        {
            int mid = left + len - 1;
            int right = min(left + 2 * len - 1, n - 1);
            merge(arr, left, mid, right, temp);
        }
    }
}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "排序前: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    mergeSort(arr);

    cout << "排序后: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
