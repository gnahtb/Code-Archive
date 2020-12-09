#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define sqr(a) (a) * (a)

const int mod = 1E9 + 7;
const int limit = 1E5 + 5;

int n, c[limit], f[limit], t[limit];

void prep()
{
    memset(t, 0, sizeof t);
    int cur = 1;
    for (int i = 0; i <= 1E5; ++i)
    {
        t[i] = (cur + mod - 1) % mod;
        (cur += cur) %= mod;
    }
}

void enter()
{
    memset(c, 0, sizeof c);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        for (int d = 1; sqr(d) <= a; ++d)
        {
            if (a % d != 0) continue;
            ++c[d]; if (a / d != d) ++c[a / d];
        }
    }
}

void solve()
{
    memset(f, 0, sizeof f);
    for (int i = 1E5; i > 0; --i)
    {
        f[i] = t[c[i]];
        for (int j = i + i; j <= 1E5; j += i)
            ((f[i] -= f[j]) += mod) %= mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    prep();
    enter();
    solve();
    cout << f[1] << "\n";
    return 0;
}
