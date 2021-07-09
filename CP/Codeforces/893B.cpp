#include <cstdio>
#include <iostream>

using namespace std;

#define long long long

long n, pw[25];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    pw[0] = 1;
    for (int i = 1; i < 18; ++i) pw[i] = pw[i - 1] * 2;
    for (int i = n; i > 0; i--)
        if (n % i == 0)
        {
            bool flag = false;
            for (int j = 1; j < 18; ++j)
                if ((pw[j] - 1) * pw[j - 1] == i)
                {
                    flag = true;
                    break;
                }
            if (flag)
            {
                cout << i;
                return 0;
            }
        }
    return 0;
}
