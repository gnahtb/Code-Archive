#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

const int maxN = 2E5 + 5;

int n;
ll x, k, a[maxN], c[70], ans = 0;

ll get_bit(ll state, ll index) { return (state >> index) & 1LL; }

void solve()
{
    memset(c, 0, sizeof c);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 65; ++j) c[j] += get_bit(a[i], j);
    x = pow(x, k);
    for (int i = 0; i < n; ++i)
    {
        ll tmp = a[i] * x;
        for (int j = 0; j < 65; ++j)
            if (c[j] > get_bit(a[i], j)) tmp |= (1LL << ll(j));
        ans = max(ans, tmp);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%lld%lld", &n, &k, &x);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    solve();
    printf("%lld\n", ans);
    return 0;
}
