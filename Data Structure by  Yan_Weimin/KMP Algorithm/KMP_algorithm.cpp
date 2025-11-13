#include <iostream>
#include <cstring>
using namespace std;

int *buildNext(char *P)
{
    int m = strlen(P), j = 0;
    int *next = new int[m];
    int t = next[0] = -1;
    while (j < m - 1)
        if (0 > t || P[t] == P[j])
        {
            ++t;
            ++j;
            next[j] = t;
        }
        else
            t = next[t];
    return next;
}

int match(char *P, char *T)
{
    int *next = buildNext(P);
    int n = (int)strlen(T), i = 0;
    int m = (int)strlen(P), j = 0;
    while ((j < m) && (i < n))
    {
        if (0 > j || T[i] == P[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    delete[] next;
    return i - j;
}

int main(void)
{
    char T[] = "acabaabaabcacaabc";
    char P[] = "aabcac";
    int number = match(P, T);
    cout << number;
}