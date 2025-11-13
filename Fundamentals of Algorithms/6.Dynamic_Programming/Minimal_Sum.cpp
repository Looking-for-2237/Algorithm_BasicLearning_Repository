// minimal_sum_with_m_plus_ll.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 4; // 足够大，避免加法溢出

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int m;
    if (!(cin >> s >> m))
    {
        cerr << "Input: <digits_string> <m>\n";
        return 0;
    }

    int n = (int)s.size();
    if (n < m + 1)
    {
        cout << "Impossible\n";
        return 0;
    }
    // 如果 n > 18 警告（可能溢出）
    if (n > 18)
    {
        cerr << "Warning: n = " << n << " > 18, some Num(i,j) may overflow long long. "
             << "Use BigInt/Boost or ensure n <= 18.\n";
        // 仍然继续运行，但结果未必正确
    }

    // 1-based Num[i][j] (i<=j)
    vector<vector<ll>> Num(n + 2, vector<ll>(n + 2, 0));
    for (int i = 1; i <= n; ++i)
    {
        ll val = 0;
        for (int j = i; j <= n; ++j)
        {
            int d = s[j - 1] - '0';
            // 检查乘10加法是否会溢出
            if (val > (LLONG_MAX - d) / 10)
            {
                // 溢出 -> 标记为 INF (不可用)
                Num[i][j] = INF;
            }
            else
            {
                val = val * 10 + d;
                Num[i][j] = val;
            }
        }
    }

    // dp[k][len] : 在前 len 个数字里放 k 个加号的最小值
    vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, INF));
    for (int len = 1; len <= n; ++len)
        dp[0][len] = Num[1][len];

    for (int k = 1; k <= m; ++k) // k = 当前要插入的加号数
    {
        for (int len = 1; len <= n; ++len) // len = 当前考虑前多少个数字
        {
            if (len < k + 1)
            {
                dp[k][len] = INF;
                continue;
            }
            ll best = INF;
            for (int i = k; i <= len - 1; ++i)
            /*i 表示最后一个加号放在第 i 个数字后面
            那么：
                前 i 个数字分成 k-1 段 → dp[k-1][i]
                后 i+1..len 的数字 → Num[i+1][len]*/
            {
                if (dp[k - 1][i] == INF || Num[i + 1][len] == INF)
                    continue;
                ll cand;
                // 检查加法是否溢出 (虽然用 INF 作保护)
                if (dp[k - 1][i] > LLONG_MAX - Num[i + 1][len])
                    cand = INF;
                else
                    cand = dp[k - 1][i] + Num[i + 1][len];
                if (cand < best)
                    best = cand;
            }
            dp[k][len] = best;
        }
    }

    ll ans = dp[m][n];
    if (ans >= INF)
        cout << "Impossible\n";
    else
        cout << ans << '\n';

    return 0;
}
