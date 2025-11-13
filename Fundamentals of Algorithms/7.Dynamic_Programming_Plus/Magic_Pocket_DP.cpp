#include <iostream>
#include <cstring>
using namespace std;
int a[30];
int N;
int Ways[50][30];
int main(void)
{
    cin >> N;
    memset(Ways, 0, sizeof(Ways));
    for (int i = 1; i <= N; ++i)
    {
        cin >> a[i];
        Ways[0][i] = 1; // 空集：用前 i 件物品凑成体积 0 的方案为 1
    }
    Ways[0][0] = 1;               // 同上，k=0 情况
    for (int w = 1; w <= 40; ++w) // 对每个目标体积
    {
        for (int k = 1; k <= N; ++k) // 对前 k 件物品
        {
            Ways[w][k] = Ways[w][k - 1]; // 不选第 k 件
            if (w - a[k] >= 0)
                Ways[w][k] += Ways[w - a[k]][k - 1]; // 选第 k 件（若可行）
        }
    }
    cout << Ways[40][N];
    return 0;
}