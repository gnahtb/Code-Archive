#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define long long long

const int limit = 1E6 + 5;

long n, a[limit], f[limit], l[limit];
double ans = 0;

void solve()
{
    memset(f, 0, sizeof f);
    memset(l, 0, sizeof l);
    for (int i = 1; i <= n; ++i)
    {
        f[i] = f[i - 1] + i - l[a[i]];
        l[a[i]] = i;
        ans += f[i];
    }
    ans = ans * 2 - n;
    ans = ans / double(n * n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    solve();
    (cout << fixed).precision(9);
    cout << ans;
    return 0;
}
