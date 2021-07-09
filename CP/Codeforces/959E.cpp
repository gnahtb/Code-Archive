#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

ll n, f[50], ans = 0;

ll getBit(ll state, ll index) { return (state >> index) & 1LL; }

void solve()
{
    memset(f, 0, sizeof f);
    for (int i = 1; i < 45; ++i)
        f[i] = (f[i - 1] << 1LL) + (1LL << ll(i - 1));
    ll tmp = 0;
    for (int i = 0; i < 45; ++i)
        if (getBit(n, ll(i))) ans += f[i] + (1LL << ll(i));
    ans -= tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%lld", &n); --n;
    solve();
    printf("%lld\n", ans);
    return 0;
}
