#include <bits/stdc++.h>

using namespace std;

#define odd(a) ((a) & 1)
#define sz(a) (int)a.size()

const int LIM = 102, CHR_MAX = 26;
const int INF = 1e9;

void zf(string s, int (&z)[LIM]) {
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

void build(string &s, int (&t)[LIM][CHR_MAX]) {
  int z[LIM];
  string cur = "";
  for (int i = sz(s); i >= 0; --i) {
    if (i < sz(s)) cur = s[i] + cur;
    for (char j = 'a'; j <= 'z'; ++j) {
      string tmp = j + cur;
      zf(tmp + '#' + s, z);
      t[sz(s) - i][j - 'a'] = 0;
      for (int k = 1; k <= sz(s); ++k)
        if (k + z[k + sz(tmp)] > sz(s)) {
          t[sz(s) - i][j - 'a'] = sz(s) - k + 1;
          break;
        }
    }
  }
}

string a, b, c;
int nxa[LIM][CHR_MAX], nxb[LIM][CHR_MAX], f[2][LIM][LIM];

inline void opt(int &a, int b) {
  if (a < b) a = b;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> c >> a >> b;
  build(a, nxa);
  build(b, nxb);

  fill(f[odd(sz(c))][0], f[odd(sz(c))][LIM], -INF);
  f[odd(sz(c))][0][0] = 0;
  for (int i = sz(c); i; --i) {
    fill(f[odd(i - 1)][0], f[odd(i - 1)][LIM], -INF);
    for (int j = 0; j <= sz(a); ++j)
      for (int k = 0; k <= sz(b); ++k) {
        if (f[odd(i)][j][k] == -INF) continue;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
          if (c[i - 1] == '*' || c[i - 1] == ch) {
            int u = nxa[j][ch - 'a'], v = nxb[k][ch - 'a'];
            opt(f[odd(i - 1)][u][v], f[odd(i)][j][k] + (u == sz(a)) - (v == sz(b)));
          }
        }
      }
  }

  int ans = -INF;
  for (int j = 0; j <= sz(a); ++j)
    for (int k = 0; k <= sz(b); ++k)
      opt(ans, f[0][j][k]);

  cout << ans << "\n";
  return 0;
}
