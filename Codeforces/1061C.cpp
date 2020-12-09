#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 1e5 + 5;
const int LIM = 1e6 + 5;
const ll MOD = 1e9 + 7;

int n, a[N_MAX];
set<int, greater<int>> s;
ll f[LIM], ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        s.clear();
        for (int j = 1; j * j <= a[i]; ++j)
            if (a[i] % j == 0) s.insert(j), s.insert(a[i] / j);
        for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
            int t = *it;
            (f[t] += f[t - 1]) %= MOD;
        }
    }
    for (int i = 1; i <= n; ++i) (ans += f[i]) %= MOD;
    cout << ans << "\n";
    return 0;
}
