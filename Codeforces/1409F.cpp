#include <bits/stdc++.h>

using namespace std;

const int N = 202;

int n, k, f[N][N][N];
string s, t;

void Opt(int& x, int y) {
  if (x < y) x = y;
}

int main() {
  cin >> n >> k >> s >> t;
  memset(f, -1, sizeof(f));
  f[0][0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      for (int u = 0; u <= k; ++u) {
        // remain
        if (s[i - 1] != t[0] && s[i - 1] != t[1])
          Opt(f[i][j][u], f[i - 1][j][u]);

        if (t[0] != t[1]) {
          // change to t[0]
          if (j > 0 && u >= (t[0] != s[i - 1]))
            Opt(f[i][j][u], f[i - 1][j - 1][u - (t[0] != s[i - 1])]);

          // change to t[1]
          if (u >= (t[1] != s[i - 1]) && f[i - 1][j][u - (t[1] != s[i - 1])] >= 0)
            Opt(f[i][j][u], f[i - 1][j][u - (t[1] != s[i - 1])] + j);
        } else {
          if (j > 0 && u >= (t[0] != s[i - 1]) && f[i - 1][j - 1][u - (t[0] != s[i - 1])] >= 0)
            Opt(f[i][j][u], f[i - 1][j - 1][u - (t[0] != s[i - 1])] + j - 1);
        }
      }
    }
  }
  int ans = 0;
  for (int j = 0; j <= n; ++j) {
    for (int u = 0; u <= k; ++u) {
      Opt(ans, f[n][j][u]);
    }
  }
  cout << ans;
  return 0;
}