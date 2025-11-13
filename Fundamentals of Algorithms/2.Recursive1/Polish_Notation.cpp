#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
double exp()
{
    char s[20];
    cin >> s;
    switch (s[0])
    {
    case '+':
        return exp() + exp();
    case '-':
        return exp() - exp();
    case '*':
        return exp() * exp();
    case '/':
        return exp() / exp();
    default:
        return atof(s);
        break;
    }
}
int main(void)
{
    printf("%lf", exp());
    return 0;
}