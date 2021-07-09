#include <cstdio>
#include <iostream>

using namespace std;

#define long long long
#define sqr(a) (a)*(a)

const long mod = 1e9 + 7;

long n, m, k;

long powDaC(long a, long b)
{
    if (b == 0) return 1;
    long res = sqr(powDaC(a, b / 2)) % mod;
    if (b & 1) res = (res * a) % mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    if (k == -1 & (n + m) & 1)
    {
        cout << 0;
        return 0;
    }
    cout << powDaC(powDaC(2, m - 1), n - 1);
    return 0;
}
