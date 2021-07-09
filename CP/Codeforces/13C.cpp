#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll inf = 1E18;

int n;
ll a[5005], f[5][5005];
vector<ll> b;

void solve()
{
    memset(f, 0, sizeof f); f[0][0] = f[1][0] = inf;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= b.size(); ++j)
            f[i & 1][j] = min(f[i & 1][j - 1], f[(i - 1) & 1][j] + abs(a[i] - b[j - 1]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], b.push_back(a[i]);
    sort(b.begin(), b.end());
    vector<ll>::iterator it = unique (b.begin(), b.end());
    b.resize(distance(b.begin(), it));
    solve();
    cout << f[n & 1][b.size()] << "\n";
    return 0;
}
