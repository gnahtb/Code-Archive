#include <cstring>
#include <iostream>

using namespace std;

#define sz(a) (int)a.size()

typedef long long ll;

const int N = 705;
const ll mod = 1000000007;

string s;
ll f[N][N][3][3], ans = 0;

void solve(int l, int r) {
  memset(f[l][r], 0, sizeof (f[l][r]));
  if (l + 1 == r) {
    f[l][r][0][1] = f[l][r][0][2] = f[l][r][1][0] = f[l][r][2][0] = 1;
    return;
  }
  int i = l;
  for (int c = 1; i <= r; c += s[++i] == '(' ? 1 : -1) if (!c) break;
  if (i == r) {
    solve(l + 1, r - 1);
    for (int i0 = 0; i0 < 3; ++i0)
      for (int j0 = 0; j0 < 3; ++j0) if ((!i0) ^ (!j0))
        for (int i1 = 0; i1 < 3; ++i1) if (!i0 || !i1 || i0 != i1)
          for (int j1 = 0; j1 < 3; ++j1) if (!j0 || !j1 || j0 != j1)
            (f[l][r][i0][j0] += f[l + 1][r - 1][i1][j1]) %= mod;
  } else {
    solve(l, i);
    solve(i + 1, r);
    for (int i0 = 0; i0 < 3; ++i0)
      for (int j0 = 0; j0 < 3; ++j0)
        for (int i1 = 0; i1 < 3; ++i1)
          for (int j1 = 0; j1 < 3; ++j1) if (!j0 || !i1 || j0 != i1)
            (f[l][r][i0][j1] += f[l][i][i0][j0] * f[i + 1][r][i1][j1]) %= mod;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> s;
  solve(0, sz(s) - 1);
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      (ans += f[0][sz(s) - 1][i][j]) %= mod;
  cout << ans << "\n";
  return 0;
}
