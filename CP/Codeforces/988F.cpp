#include <bits/stdc++.h>

using namespace std;

#define FOR(i, L, R) for (int i = L; i <= R; ++i)
#define fi first
#define se second

typedef pair<int, int> ii;

const int lim = 5005;

int a, n, m, f[lim][lim], ans = INT_MAX;
ii u[lim];
bool c[lim];

template <typename T>
void minimize(T &a, T b) { if (a > b) a = b; }

void enter()
{
    memset(c, false, sizeof c);
    cin >> a >> n >> m;
    FOR(i, 1, n)
    {
        int l, r;
        cin >> l >> r;
        FOR(j, l + 1, r) c[j] = true;
    }
    FOR(i, 1, m) cin >> u[i].fi >> u[i].se;
}

void solve()
{
    fill(f[0], f[0] + m + 1, INT_MAX);
    f[0][0] = 0;
    FOR(i, 1, a)
    {
        fill(f[i], f[i] + m + 1, INT_MAX);
        FOR(j, 1, m) if (u[j].fi < i)
        {
            f[i][j] = f[i - 1][j];
            if (i == u[j].fi + 1)
                FOR(k, 0, m) minimize(f[i][j], f[i - 1][k]);
            if (f[i][j] == INT_MAX) continue;
            f[i][j] += u[j].se;
        }
        if (c[i]) continue;
        FOR(j, 0, m) minimize(f[i][0], f[i - 1][j]);
    }
    FOR(j, 0, m) minimize(ans, f[a][j]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    enter();
    solve();
    if (ans == INT_MAX) ans = -1;
    cout << ans << "\n";
    return 0;
}
