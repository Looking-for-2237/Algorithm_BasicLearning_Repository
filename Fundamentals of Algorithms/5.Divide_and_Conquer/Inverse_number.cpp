#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 归并并统计 [l..mid] 与 [mid+1..r] 之间的逆序对数量
ll merge_count(vector<int> &a, vector<int> &tmp, int l, int mid, int r)
{
    int i = l, j = mid + 1, k = l;
    ll inv = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            tmp[k++] = a[i++];
        }
        else
        {
            // a[i] > a[j]，则 a[i..mid] 都与 a[j] 形成逆序对
            tmp[k++] = a[j++];
            inv += (ll)(mid - i + 1);
        }
    }
    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];
    for (int t = l; t <= r; ++t)
        a[t] = tmp[t];
    return inv;
}

// 递归分治：返回区间 [l..r] 的逆序对数量
ll sort_count(vector<int> &a, vector<int> &tmp, int l, int r)
{
    if (l >= r)
        return 0;
    int mid = l + (r - l) / 2;
    ll inv = 0;
    inv += sort_count(a, tmp, l, mid);
    inv += sort_count(a, tmp, mid + 1, r);
    inv += merge_count(a, tmp, l, mid, r);
    return inv;
}

// 对外接口
ll count_inversions(vector<int> a)
{
    int n = (int)a.size();
    vector<int> tmp(n);
    return sort_count(a, tmp, 0, n - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ll ans = count_inversions(a);
    cout << ans << "\n";
    return 0;
}
