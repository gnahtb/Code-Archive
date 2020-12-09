#include <bits/stdc++.h>

using namespace std;

#define sqr(a) (a) * (a)
#define odd(a) (a & 1)

const int maxN = 5005;

int n, a[maxN], f[maxN];
vector<int> u;

void prep()
{
    for (int i = 1; i <= n; ++i) if (a[i])
    {
        int x = abs(a[i]); a[i] /= abs(a[i]);
        while (x > 1)
        {
            int d = x, c = 0;
            for (int i = 2; sqr(i) <= x; ++i)
                if (!(x % i)) { d = i; break; }
            while (!(x % d)) x /= d, ++c;
            if (odd(c)) a[i] *= d;
        }
        u.push_back(a[i]);
    }
    sort(u.begin(), u.end());
    u.resize(distance(u.begin(), unique(u.begin(), u.end())));
}

void solve()
{
    bool e[maxN];
    memset(f, 0, sizeof f);
    for (int L = 1; L <= n; ++L)
    {
        memset(e, false, sizeof e);
        int cur = 0, R = L;
        while (R <= n && !a[R]) ++f[1], ++R;
        for (; R <= n; ++R)
        {
            if (a[R])
            {
                int p = lower_bound(u.begin(), u.end(), a[R]) - u.begin();;
                if (!e[p]) e[p] = true, ++cur;
            }
            ++f[cur];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    prep();
    solve();
    for (int i = 1; i <= n; ++i) cout << f[i] << " ";
    return 0;
}
