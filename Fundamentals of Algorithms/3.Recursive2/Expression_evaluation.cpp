#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int factor_value();
int term_value();
int expression_value();
int main()
{
    cout << expression_value() << endl;
    return 0;
}
int expression_value()
{
    int result = term_value();
    bool more = true;
    while (more)
    {
        char op = cin.peek();
        if (op == '+' || op == '-')
        {
            cin.get();
            int value = term_value();
            if (op == '+')
                result += value;
            else
                result -= value;
        }
        else
            more = false;
    }
    return result;
}
int term_value()
{
    int result = factor_value();
    while (true)
    {
        char op = cin.peek();
        if (op == '*' || op == '/')
        {
            cin.get();
            int value = factor_value();
            if (op == '*')
                result *= value;
            else
                result /= value;
        }
        else
            break;
    }
    return result;
}
int factor_value()
{
    int result = 0;
    char c = cin.peek();
    if (c == '(')
    {
        cin.get();
        result = expression_value();
        cin.get();
    }
    else
    {
        while (isdigit(c))
        {
            result = 10 * result + c - '0';
            cin.get();
            c = cin.peek();
        }
    }
    return result;
}
