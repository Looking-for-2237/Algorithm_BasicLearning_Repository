#include <bits/stdc++.h>
using namespace std;

struct Candy
{
    int v;
    int w;
    // 我们要按 v/w 从大到小排序，所以在 operator< 中返回 true 表示 "更大比率优先"
    bool operator<(const Candy &c) const
    {
        return 1LL * v * c.w > 1LL * c.v * w;
    }
};

int main()
{
    int n, W;
    if (scanf("%d%d", &n, &W) != 2)
        return 0;
    vector<Candy> candies(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &candies[i].v, &candies[i].w);
    }
    sort(candies.begin(), candies.end());
    int totalW = 0;
    double totalV = 0.0;
    for (int i = 0; i < n; ++i)
    {
        if (totalW + candies[i].w <= W)
        {
            totalW += candies[i].w;
            totalV += candies[i].v;
        }
        else
        {
            int remain = W - totalW;
            if (remain > 0)
            {
                totalV += candies[i].v * (double)remain / candies[i].w;
            }
            break;
        }
    }
    printf("%.1f\n", totalV);
    return 0;
}
