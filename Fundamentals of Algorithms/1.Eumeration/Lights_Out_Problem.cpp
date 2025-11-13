#include <memory>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int GetBit(char c, int i)
{
    return (c >> i) & 1;
}
void SetBit(char &c, int i, int v)
{
    if (v)
    {
        c |= (1 << i);
    }
    else
        c &= ~(1 << i);
}
void Flip(char &c, int i)
{
    c ^= (1 << i);
}
void OutputResult(int t, char result[])
{
    cout << "PUZZLE #" << t << endl;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            cout << GetBit(result[i], j);
            if (j < 5)
                cout << " ";
        }
        cout << endl;
    }
}
int main()
{
    char oriLights[5];
    char lights[5];
    char result[5];
    char switchs;
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        memset(oriLights, 0, sizeof(oriLights));
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                int s;
                cin >> s;
                SetBit(oriLights[i], j, s);
            }
        }
        for (int n = 0; n < 64; ++n)
        {
            memcpy(lights, oriLights, sizeof(oriLights));
            switchs = n;
            for (int i = 0; i < 5; ++i)
            {
                result[i] = switchs;
                for (int j = 0; j < 6; ++j)
                {
                    if (GetBit(switchs, j))
                    {
                        if (j > 0)
                        {
                            Flip(lights[i], j - 1);
                        }
                        Flip(lights[i], j);
                        if (j < 5)
                        {
                            Flip(lights[i], j + 1);
                        }
                    }
                }
                if (i < 4)
                {
                    lights[i + 1] ^= switchs;
                }
                switchs = lights[i];
            }
            if (lights[4] == 0)
            {
                OutputResult(t, result);
                break;
            }
        }
    }
    return 0;
}