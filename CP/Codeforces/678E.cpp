#include <bits/stdc++.h>

using namespace std;

#define maximize(a, b) a = max(a, b)

const int limit = 262150;

int n;
long double p[20][20], f[limit][20], ans = 0;

int get_bit(int state, int index) { return (state >> index) & 1; }

void solve()
{
    memset(f, 0, sizeof f);
    f[1][0] = 1;
    for (int mask = 2; mask < 1 << n; ++mask)
    {
        vector<int> u;
        for (int i = 0; i < n; ++i) if (get_bit(mask, i)) u.push_back(i);
        for (int i: u)
            for (int j: u) if (i != j)
                maximize(f[mask][i], p[i][j] * f[mask ^ (1 << j)][i] + p[j][i] * f[mask ^ (1 << i)][j]);
    }
    for (int i = 0; i < n; ++i) maximize(ans, f[(1 << n) - 1][i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> p[i][j];
    (cout << fixed).precision(10);
    solve();
    cout << ans << "\n";
    return 0;
}
