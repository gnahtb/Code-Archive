#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int NMAX = 2005, HMAX = 2005;
const ll MOD = 1E9 + 7;

int n, h, a[NMAX];
ll f[NMAX][HMAX];

void solve() {
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int t = h - a[i];
        //open a new bracket
        if (t) (f[i][t] += f[i - 1][t - 1]) %= MOD;
        //close a previously opened bracket
        if (t) (f[i][t - 1] += f[i - 1][t] * t) %= MOD;
        //open and close (vise versa) a pair of brackets immediately
        if (t) (f[i][t - 1] += f[i - 1][t - 1] * t) %= MOD;
        //do nothing
        (f[i][t] += f[i - 1][t]) %= MOD;
    }
    cout << f[n][0] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> h;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > h) { cout << "0\n"; return 0; }
    }
    solve();
    return 0;
}
