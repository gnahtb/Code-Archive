/*********************************************************************
2 key observations:
- For each i, there are almost 30 distinct values of cost([x, i]).
- If cost([x, i]) = cost([y, i]) = d (x < y), f[u - 1][y - 1] + d will 
be more optimal.

Author: thang040602
*********************************************************************/
#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
#define sz(a) (int)a.size()
#define fi first
#define se second
 
typedef long long ll;
typedef pair<int, int> ii;
 
const int N = 5005;
 
int t, n, k, a[N];
ll f[N][N];
vector<ii> u[N];
 
void reset() {
    fill(a, a + N, 0);
    fill(f[0], f[N], 0);
    for (int i = 0; i < N; ++i) u[i].clear();
}
 
void prep() {
    for (int i = 1; i <= n; ++i) {
        int cur = 0;
        for (int j = i; j; --j) {
            if ((cur | a[j]) > cur) u[i].push_back({cur | a[j], j});
            cur |= a[j];
        }
    }
}
 
void solve() {
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= n; ++j)
            for (ii t : u[j]) {
                int x = t.fi, p = t.se;
                f[i][j] = max(f[i][j], f[i - 1][p - 1] + x);
            }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        reset();
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        prep();
        solve();
        cout << f[k][n] << "\n";
    }
    return 0;
} 