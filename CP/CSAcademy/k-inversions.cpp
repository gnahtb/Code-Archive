#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int lim = 1E5 + 5;

int main()
{
    ll n, k, x = 1, t, d, p[lim];
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    while (x * (x + 1) <= k * 2) ++x;
    d = k - (x - 1) * x / 2;
    t = n - x - (d > 0);
    x = 0;
    for (int i = 1; i <= t; ++i) p[i] = ++x;
    for (int i = n; i > t; --i)
    {
        p[i] = ++x; --d;
        if (d == 0) p[++t] = ++x;
    }
    for (int i = 1; i <= n; ++i) cout << p[i] << " ";
    return 0;
}