#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(a) (int)a.size()
 
typedef long long ll;
 
const int N_MAX = 2005, LEN_MAX = 2005, CHR_MAX = 26;
const ll INF = 3E18;
 
int n, a, b, c;
string s;
bool avail[N_MAX][CHR_MAX];
ll f[LEN_MAX][N_MAX][2], ans = INF;
 
template <typename T>
void minimize(T &a, T b) { if (a > b) a = b; }
 
#define nxt (j + 1) % n
#define pre (j + n - 1) % n
void solve() {
    fill(f[0][0], f[LEN_MAX - 1][N_MAX], INF);
    f[0][0][1] = 0;
    f[0][1][0] = a;
    for (int j = 1; j < n; ++j)
        f[0][nxt][0] = f[0][j][0] + b;
    for (int i = 1; i <= sz(s); ++i) {
        for (int j = 0; j < n; ++j) {
            if (avail[j][s[i - 1] - 'a'])
                minimize(f[i][j][1], min(f[i - 1][j][0], f[i - 1][j][1]) + c);
            minimize(f[i][j][0], min(f[i][pre][1] + a, f[i][pre][0] + b));
        }
        for (int j = 0; j < n; ++j)
            minimize(f[i][j][0], min(f[i][pre][1] + a, f[i][pre][0] + b));
    }
    for (int j = 0; j < n; ++j) minimize(ans, f[sz(s)][j][1]);
    if (ans == INF) ans = -1;
}
#undef nxt
#undef pre
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b >> c;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < sz(s); ++j) avail[i][s[j] - 'a'] = true;
    }
    cin >> s;
    solve();
    cout << ans << "\n";
    return 0;
}