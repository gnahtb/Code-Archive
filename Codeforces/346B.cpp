#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

const int LIM = 105, CHR_MAX = 26;

string s1, s2, virus, ans;
int nxt[LIM][CHR_MAX];
string f[LIM][LIM][LIM];

void z_func(string s, int *z) {
    fill(z, z + sz(s), 0);
    for (int i = 1, l = 0, r = 0; i < sz(s); ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < sz(s) && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 >= r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

void build() {
    int z[LIM << 1];
    string cur;
    for (int i = sz(virus); i >= 0; --i) {
        if (i < sz(virus)) cur = virus[i] + cur;
        for (char j = 'A'; j <= 'Z'; ++j) {
            string tmp = j + cur;
            z_func(tmp + '*' + virus, z);
            nxt[i][j - 'A'] = 0;
            for (int k = 1; k <= sz(virus); ++k)
                if (k + z[k + sz(tmp)] > sz(virus)) {
                    nxt[i][j - 'A'] = sz(virus) - k + 1;
                    break;
                }
        }
    }
}

inline void opt(string &a, string b) {
    if (a == "*" || sz(a) < sz(b)) a = b;
}

void solve() {
    for (int i = 0; i < LIM; ++i)
        for (int j = 0; j < LIM; ++j)
            for (int k = 0; k < LIM; ++k) f[i][j][k] = "*";
    // base cases here
    for (int i = 0; i <= sz(s1); ++i) f[i][sz(s2)][0] = "";
    for (int j = 0; j <= sz(s2); ++j) f[sz(s1)][j][0] = "";
    // solve
    for (int i = sz(s1) - 1; i >= 0; --i)
        for (int j = sz(s2) - 1; j >= 0; --j) {
            for (int k = 0; k < sz(virus); ++k) {
                if (f[i + 1][j][k] != "*")
                    opt(f[i][j][k], f[i + 1][j][k]);
                if (f[i][j + 1][k] != "*")
                    opt(f[i][j][k], f[i][j + 1][k]);
                if (f[i + 1][j + 1][k] != "*" && s1[i] == s2[j])
                    opt(f[i][j][nxt[sz(virus) - k][s1[i] - 'A']], s1[i] + f[i + 1][j + 1][k]);
            }
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> s1 >> s2 >> virus;
    build();
    solve();
    string ans = "";
    for (int k = 0; k < sz(virus); ++k)
        opt(ans, f[0][0][k]);
    cout << (sz(ans) > 0 ? ans : "0") << "\n";
    return 0;
}
