#include <bits/stdc++.h>

using namespace std;

const int mod = 1E9 + 7;

int f[105][2605], t;
char s[200];

void prep()
{
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for (int len = 1; len <= 100; ++len)
        for (int sum = 1; sum <= 2600; ++sum)
            for (int i = 1; i <= 26; ++i)
            {
                if (i > sum) continue;
                (f[len][sum] += f[len - 1][sum - i]) %= mod;
            }
}

int main()
{
    ios_base::sync_with_stdio(false);
    prep();
    scanf("%d\n", &t);
    while (t--)
    {
        scanf("%s", &s);
        int len = 0, sum = 0;
        for(len = 0; s[len]; ++len) sum += s[len] - 'a' + 1;
        printf("%d\n", f[len][sum] - 1);
    }
    return 0;
}
