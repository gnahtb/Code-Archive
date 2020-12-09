#include <cstdio>
#include <iostream>

using namespace std;

#define long long long
#define sqr(a) (a) * (a)

const long mod = 1E9 + 7;

long a, b, n, x, ans;

long power(long a, long b)
{
    if (b == 0) return 1;
    long res = sqr(power(a, b >> 1)) % mod;
    if (b & 1 == 1) res = (res * a) % mod;
    return res;
}

void solve()
{
    long p = power(a, n), t = n % mod;
    ans = p * x % mod;
    if (a > 1) t = (p - 1) * power(a - 1, mod - 2) % mod;
    ans = (ans + t * b % mod) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> n >> x;
    solve();
    cout << ans;
    return 0;
}
