#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> pll;

int n;
ll ans = 0, cur = 0;
vector<pll> a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string t;
        ll s = 0, h = 0;
        cin >> t;
        for (char c: t) if (c == 's') ++s; else ans += s, ++h;
        a.push_back({h, s});
    }
    sort(a.begin(), a.end(), [](pll x, pll y) { return x.se * y.fi > x.fi * y.se; });
    cur = 0;
    for (pll p: a) ans += cur * p.fi, cur += p.se;
    cout << ans << "\n";
    return 0;
}
