#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int N = 2002;
const ll MOD = 1e9 + 7;
 
int n, k;
char s[N];
 
// 0 -> smaller
// 1 -> equal
// 2 -> larger
ll f[N][N][3];
 
inline void Add(ll& x, ll y) {
    (x += y) %= MOD;
}
 
void Solve() {
    f[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            Add(f[i][j][1], f[i - 1][j][0] + f[i - 1][j][1] + f[i - 1][j][2]);
            Add(f[i][j][0], f[i][j][1] * (s[i - 1] - 'a'));
 
            for (int t = 0; t < j / (n - i + 1); ++t) {
                if (i >= t + 1) {
                    int u = i - t - 1;
                    ll tmp1 = f[u][j - (t + 1) * (n - i + 1)][0] + f[u][j - (t + 1) * (n - i + 1)][2];
                    ll tmp = tmp1 * ('z' - s[i - 1]);
                    Add(f[i][j][2], tmp);
                }
            }
        }
    }
}
 
int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    Solve();
    ll ans = f[n][k][0];
    Add(ans, f[n][k][1]);
    Add(ans, f[n][k][2]);
    printf("%lld\n", ans);
    return 0;
}
