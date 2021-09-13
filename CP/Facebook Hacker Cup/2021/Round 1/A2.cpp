#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const int N = 8e5 + 2;

int test, n;
ll pre[N], f[N];
string s;

int main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> test;
    for (int itest = 1; itest <= test; ++itest) {
        cin >> n >> s;
        for (int i = 0; i <= n; ++i) pre[i] = -1, f[i] = 0;
        int curo = -1, curx = -1;
        for (int i = 0; i < n; ++i)
            if (s[i] == 'O') {
                curo = i;
                pre[i] = curx;
            } else if (s[i] == 'X') {
                curx = i;
                pre[i] = curo;
            } else {
                if (i) pre[i] = pre[i - 1];
                else pre[i] = -1;
            }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i) f[i] = f[i - 1];
            if (pre[i] != pre[i - 1])
                f[i] += pre[i] + 1;
            (ans += f[i]) %= MOD;
        }
        cout << "Case #" << itest << ": " << ans << endl;
    }
    return 0;
}