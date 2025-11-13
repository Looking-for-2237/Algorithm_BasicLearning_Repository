#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#define EPS 1e-6

struct Node
{
    double val;
    string expr;
};

bool isZero(double x)
{
    return fabs(x) <= EPS;
}

bool count24(Node a[], int n, string &solution)
{
    if (n == 1)
    {
        if (isZero(a[0].val - 24))
        {
            solution = a[0].expr; // 保存表达式
            return true;
        }
        else
            return false;
    }

    Node b[5];
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int m = 0;
            for (int k = 0; k < n; ++k)
                if (k != i && k != j)
                    b[m++] = a[k];

            // 枚举运算
            // 1. 加法
            b[m] = {a[i].val + a[j].val, "(" + a[i].expr + "+" + a[j].expr + ")"};
            if (count24(b, m + 1, solution))
                return true;

            // 2. 减法
            b[m] = {a[i].val - a[j].val, "(" + a[i].expr + "-" + a[j].expr + ")"};
            if (count24(b, m + 1, solution))
                return true;

            b[m] = {a[j].val - a[i].val, "(" + a[j].expr + "-" + a[i].expr + ")"};
            if (count24(b, m + 1, solution))
                return true;

            // 3. 乘法
            b[m] = {a[i].val * a[j].val, "(" + a[i].expr + "*" + a[j].expr + ")"};
            if (count24(b, m + 1, solution))
                return true;

            // 4. 除法
            if (!isZero(a[j].val))
            {
                b[m] = {a[i].val / a[j].val, "(" + a[i].expr + "/" + a[j].expr + ")"};
                if (count24(b, m + 1, solution))
                    return true;
            }
            if (!isZero(a[i].val))
            {
                b[m] = {a[j].val / a[i].val, "(" + a[j].expr + "/" + a[i].expr + ")"};
                if (count24(b, m + 1, solution))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    Node a[4];
    while (true)
    {
        for (int i = 0; i < 4; ++i)
        {
            cin >> a[i].val;
            a[i].expr = to_string((int)a[i].val); // 初始化表达式
        }
        if (isZero(a[0].val) && isZero(a[1].val) && isZero(a[2].val) && isZero(a[3].val))
            break;

        string solution;
        if (count24(a, 4, solution))
            cout << "YES: " << solution << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
