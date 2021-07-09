#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll oo = 1e18;

int n;
vector<int> a, val;
vector<vector<int>> IDX;
vector<array<ll, 2>> f;

void Opt(ll& x, ll y) {
    if (x > y) x = y;
}

int main() {
    cin >> n;
    a.resize(n + 2);
    val.push_back(0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        val.push_back(a[i]);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    IDX.resize(val.size() + 2);
    for (int i = 1; i <= n; ++i) {
        int po = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
        IDX[po].push_back(i);
    }
    IDX[0].push_back(1);
    f.resize(val.size() + 2, {oo, oo});
    f[0] = {0, 0};
    for (int i = 1; i < (int)val.size(); ++i) {
        Opt(f[i][0], f[i - 1][0] + abs(IDX[i - 1].front() - IDX[i].back()) + abs(IDX[i].back() - IDX[i].front()));
        Opt(f[i][0], f[i - 1][1] + abs(IDX[i - 1].back() - IDX[i].back()) + abs(IDX[i].back() - IDX[i].front()));
        Opt(f[i][1], f[i - 1][0] + abs(IDX[i - 1].front() - IDX[i].front()) + abs(IDX[i].back() - IDX[i].front()));
        Opt(f[i][1], f[i - 1][1] + abs(IDX[i - 1].back() - IDX[i].front()) + abs(IDX[i].back() - IDX[i].front()));
    }
    ll ans = oo;
    Opt(ans, f[val.size() - 1][0] + n);
    Opt(ans, f[val.size() - 1][1] + n);
    cout << ans << "\n";
    return 0;
}