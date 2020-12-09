#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll X, d;
vector<ll> a;

ll getBit(ll state, ll index) { return (state >> index) & 1LL; }

void solve()
{
    ll cur = 1;
    for (int i = 0; i < 31; ++i)
    {
        if (!getBit(X, i)) continue;
        for (int j = 1; j <= i; ++j) a.push_back(cur);
        a.push_back(cur + d);
        cur += d + d;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%lld%lld", &X, &d);
    solve();
    printf("%d\n", int(a.size()));
    for (ll v: a) printf("%lld ", v);
    return 0;
}
