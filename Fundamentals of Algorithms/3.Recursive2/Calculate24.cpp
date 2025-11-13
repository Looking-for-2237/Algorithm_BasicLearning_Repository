#include <iostream>
#include <cmath>
using namespace std;
double a[5];
#define EPS 1e-6
bool isZero(double x)
{
    return fabs(x) <= EPS;
}
bool count24(double a[], int n) // 用数组a里的 n个数，计算24
{
    if (n == 1)
    {
        if (isZero(a[0] - 24))
            return true;
        else
            return false;
    }
    double b[5];
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j) // 枚举两个数的组合
        {
            int m = 0; // 还剩下m个数, m = n - 2
            for (int k = 0; k < n; ++k)
                if (k != i && k != j)
                    b[m++] = a[k]; // 把其余数放入b
            b[m] = a[i] + a[j];
            if (count24(b, m + 1))
                return true;
            b[m] = a[i] - a[j];
            if (count24(b, m + 1))
                return true;
            b[m] = a[j] - a[i];
            if (count24(b, m + 1))
                return true;
            b[m] = a[i] * a[j];
            if (count24(b, m + 1))
                return true;
            if (!isZero(a[j]))
            {
                b[m] = a[i] / a[j];
                if (count24(b, m + 1))
                    return true;
            }
            if (!isZero(a[i]))
            {
                b[m] = a[j] / a[i];
                if (count24(b, m + 1))
                    return true;
            }
        }
    return false;
}
int main()
{
    while (true)
    {
        for (int i = 0; i < 4; ++i)
            cin >> a[i];
        if (isZero(a[0]) && isZero(a[1]) && isZero(a[2]) && isZero(a[3]))
            break;
        if (count24(a, 4))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}