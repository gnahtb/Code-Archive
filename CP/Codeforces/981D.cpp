#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int lim = 55;

int n, k;
ll a[lim], f[lim][lim], ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int t = 60; t >= 0; --t)
    {
        ll tmp = ans + (1LL << t);
        memset(f, -1, sizeof f);
        f[0][0] = 1152921504606846975;
        for (int i = 1; i <= k; ++i)
            for (int l = i; l <= n; ++l)
            {
                if (f[i - 1][l - 1] == -1) continue;
                ll cur = 0;
                for (int r = l; r <= n; ++r)
                {
                    cur += a[r];
                    if ((tmp & cur) == tmp)
                        f[i][r] = max(f[i][r], f[i - 1][r - 1] & cur);
                }
            }
        if (f[k][n] >= 0) ans += 1LL << t;
    }
    cout << ans << "\n";
    return 0;
}
