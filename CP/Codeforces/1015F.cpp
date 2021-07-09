#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

typedef long long ll;

const int LEN_MAX = 205, CHR_MAX = 2;
const ll MOD = 1E9 + 7;

int n, nxt[LEN_MAX][CHR_MAX];
ll dp[LEN_MAX][LEN_MAX][LEN_MAX];
string s;

void z_function(string s, vector<int> &z) {
    z[0] = 0;
    for (int i = 1, l = 0, r = 0; i < sz(s); ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < sz(s) && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
}

void build() {
    memset(nxt, 0, sizeof nxt);
    for (int i = 0; i < sz(s); ++i) {
        string cur = "";
        for (int j = sz(s) - i; j < sz(s); ++j) cur += s[j];
        for (char c = '('; c <= ')'; ++c) {
            string tmp = c + cur + '*' + s;
            vector<int> z(sz(tmp) + 5);
            z_function(tmp, z);
            for (int j = 0; j < sz(tmp); ++j)
                if (j + z[j] == sz(tmp)) { nxt[i][c - '('] = z[j]; break; }
        }
    }
}

void solve() {
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    for (int i = 0; i < n + n; ++i)
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k < sz(s); ++k) {
                if (j) (dp[i + 1][j - 1][nxt[k][0]] += dp[i][j][k]) %= MOD;
                if (j < n) (dp[i + 1][j + 1][nxt[k][1]] += dp[i][j][k]) %= MOD;
            }
            if (j) (dp[i + 1][j - 1][sz(s)] += dp[i][j][sz(s)]) %= MOD;
            if (j < n) (dp[i + 1][j + 1][sz(s)] += dp[i][j][sz(s)]) %= MOD;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    build();
    solve();
    cout << dp[n + n][0][sz(s)] << "\n";
    return 0;
}
