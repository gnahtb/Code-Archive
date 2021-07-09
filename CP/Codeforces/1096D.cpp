#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 2;

int n;
string s;
ll a[N], f[N][4];

inline void opt(ll &a, ll b) {
    if (a < 0) a = b;
    else if (a > b) a = b;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> s;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    memset(f, -1, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'h') {
            f[i][0] = f[i - 1][0] + a[i];
            opt(f[i][1], f[i - 1][0]);
            if (f[i - 1][1] >= 0)
                opt(f[i][1], f[i - 1][1]);
            f[i][2] = f[i - 1][2];
            f[i][3] = f[i - 1][3];
        } else if (s[i - 1] == 'a') {
            f[i][0] = f[i - 1][0];
            if (f[i - 1][1] >= 0)
                f[i][1] = f[i - 1][1] + a[i];
            if (f[i - 1][1] >= 0)
                opt(f[i][2], f[i - 1][1]);
            if (f[i - 1][2] >= 0)
                opt(f[i][2], f[i - 1][2]);
            f[i][3] = f[i - 1][3];
        } else if (s[i - 1] == 'r') {
            f[i][0] = f[i - 1][0];
            f[i][1] = f[i - 1][1];
            if (f[i - 1][2] >= 0)
                f[i][2] = f[i - 1][2] + a[i];
            if (f[i - 1][2] >= 0)
                opt(f[i][3], f[i - 1][2]);
            if (f[i - 1][3] >= 0)
                opt(f[i][3], f[i - 1][3]);
        } else if (s[i - 1] == 'd') {
            f[i][0] = f[i - 1][0];
            f[i][1] = f[i - 1][1];
            f[i][2] = f[i - 1][2];
            if (f[i - 1][3] >= 0)
                f[i][3] = f[i - 1][3] + a[i];
        } else {
            f[i][0] = f[i - 1][0];
            f[i][1] = f[i - 1][1];
            f[i][2] = f[i - 1][2];
            f[i][3] = f[i - 1][3];
        }
    }

    ll ans = -1;
    opt(ans, f[n][0]);
    if (f[n][1] >= 0)
        opt(ans, f[n][1]);
    if (f[n][2] >= 0)
        opt(ans, f[n][2]);
    if (f[n][3] >= 0)
        opt(ans, f[n][3]);
    cout << ans << "\n";

    return 0;
}
