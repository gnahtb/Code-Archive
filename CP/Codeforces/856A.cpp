#include <bits/stdc++.h>

using namespace std;

int t, n, d[1000005];
vector<int> a, b, e;

void solve()
{
    for (int i = 1; i <= 1000000; ++i) if (d[i] != t)
    {
        b.push_back(i);
        for (int u: e) d[i + u] = t;
        if (b.size() >= n) break;
    }
    if (b.size() >= n)
    {
        cout << "YES\n";
        for (int u: b) cout << u << " ";
        cout << "\n";
    }
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    memset(d, -1, sizeof d);
    cin >> t;
    while (t--)
    {
        a.clear(); b.clear(); e.clear();
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int o;
            cin >> o;
            a.push_back(o);
        }
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j) e.push_back(abs(a[i] - a[j]));
        sort(e.begin(), e.end());
        unique(e.begin(), e.end());
        if (e[0] == 0) { cout << "NO\n"; continue; }
        solve();
    }
    return 0;
}
