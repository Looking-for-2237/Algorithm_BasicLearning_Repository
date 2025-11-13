#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    if (!(cin >> N))
        return 0;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    int cnt = 0;
    int total = 1 << N;
    for (int mask = 0; mask < total; ++mask)
    {
        int sum = 0;
        for (int i = 0; i < N; ++i)
            if (mask & (1 << i))
                sum += a[i];
        if (sum == 40)
            ++cnt;
    }
    cout << cnt << '\n';
    return 0;
}
