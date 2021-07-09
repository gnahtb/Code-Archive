#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int NMAX = 205;
const int KMAX = 1005;
const ll MOD = 1E9 + 7;

int n, k, a[NMAX];
ll f[2][NMAX][KMAX], ans = 0;

void solve() {
    f[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        memset(f[(i + 1) & 1], 0, sizeof f[(i + 1) & 1]);
        for (int j = 0; j <= n; ++j)
            for (int s = 0; s <= k; ++s) {
                int newval = s + j * (a[i + 1] - a[i]);
                if (newval > k) continue;
                //open a new bracket
                if (j < n) (f[(i + 1) & 1][j + 1][newval] += f[i & 1][j][s]) %= MOD;
                //close a previous bracket
                if (j) (f[(i + 1) & 1][j - 1][newval] += f[i & 1][j][s] * j) %= MOD;
                //open and close a pair of brackets immediately
                (f[(i + 1) & 1][j][newval] += f[i & 1][j][s]) %= MOD;
                //add to a previous group (bracket)
                (f[(i + 1) & 1][j][newval] += f[i & 1][j][s] * j) %= MOD;
            }
    }
    for (int s = 0; s <= k; ++s) (ans += f[n & 1][0][s]) %= MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    solve();
    cout << ans << "\n";
    return 0;
}
