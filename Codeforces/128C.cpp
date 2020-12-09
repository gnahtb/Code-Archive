#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define long long long
#define fill(a, b) memset(a, b, sizeof a);

const long mod = 1e9 + 7;

long n, m, k, c[1005][1005];

void prep()
{
    fill(c, 0);
    c[0][0] = 1;
    for (int i = 1; i <= 1000; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    prep();
    if (k * 2 > n || k * 2 > m)
    {
        cout << 0;
        return 0;
    }
    cout << c[n - 1][k * 2] * c[m - 1][k * 2] % mod;
    return 0;
}
