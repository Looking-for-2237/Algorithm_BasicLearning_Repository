// Optimize the space further by using a one-dimensional rolling array.
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int TARGET = 40;
    int N;
    if (!(cin >> N))
        return 0;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    vector<long long> dp(TARGET + 1, 0);
    dp[0] = 1; // 空集

    for (int i = 0; i < N; ++i)
    {
        int v = a[i];
        if (v > TARGET)
            continue; // 大于目标的物品不可能选
        for (int w = TARGET; w >= v; --w)
        {
            dp[w] += dp[w - v];
        }
    }

    cout << dp[TARGET] << '\n';
    return 0;
}
