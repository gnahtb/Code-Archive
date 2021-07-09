#include <bits/stdc++.h>

using namespace std;

#define sz(a) int(a.size())
#define sqr(a) (a) * (a)

const int lim = 1E6 + 5;

int n, m, f[lim], l = 1, kmax = 0;
vector<int> id[lim], ans;

void solve()
{
    memset(f, 0, sizeof f);
    for (int i = 1; i <= m; ++i)
        for (int j = i; j <= m; j += i) f[j] += sz(id[i]);
    for (int i = 1; i <= m; ++i)
        if (kmax < f[i]) kmax = f[i], l = i;
    for (int i = 1; i <= m; ++i) if (!(l % i))
        for (int v: id[i]) ans.push_back(v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        if (a <= m) id[a].push_back(i);
    }
    solve();
    sort(ans.begin(), ans.end());
    cout << l << " " << kmax << "\n";
    for (int v: ans) cout << v << " ";
    return 0;
}
