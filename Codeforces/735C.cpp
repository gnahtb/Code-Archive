#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, f[100], ans = 0;

void solve()
{
    memset(f, 0, sizeof f);
    f[0] = 1; f[1] = 2;
    for (int i = 2; i < 91; ++i) f[i] = f[i - 1] + f[i - 2];
    while (f[ans + 1] <= n) ++ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%lld", &n);
    solve();
    printf("%lld\n", ans);
    return 0;
}
