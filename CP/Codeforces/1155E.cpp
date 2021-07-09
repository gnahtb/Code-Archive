#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 11;
const ll MOD = 1e6 + 3;

ll power(ll x, ll y, ll z) {
  if (!y) return 1 % z;
  ll t = power(x, y / 2, z);
  (t *= t) %= z;
  if (y & 1) (t *= x) %= z;
  return t;
}

ll equa[N + 2][N + 2], sol[N + 2];
int pos[N + 2], piv[N + 2];

bool gauss() {
  memset(piv, -1, sizeof piv);
  memset(sol, -1, sizeof sol);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j)
      if (equa[i][j] > 0) {
        piv[i] = j;
        pos[j] = i;
        break;
      }
    if (piv[i] < 0) {
      if (equa[i][N]) return false;
      continue;
    }

    for (int j = 0; j < N; ++j) if (i != j && equa[j][piv[i]]) {
      ll tmp = power(equa[j][piv[i]], MOD - 2, MOD) * equa[i][piv[i]] % MOD;
      for (int k = 0; k <= N; ++k) {
        (equa[j][k] *= tmp) %= MOD;
        (equa[j][k] += MOD - equa[i][k]) %= MOD;
      }
    }
  }

  for (int i = 0; i < N; ++i) if (pos[i] < 0) sol[i] = 0;
  for (int i = N - 1; i >= 0; --i) {
    ll tmp = 0;
    for (int j = 0; j < N; ++j)
      if (j != piv[i]) (tmp += equa[i][j] * sol[j] % MOD) %= MOD;
    sol[piv[i]] = ((equa[i][N] - tmp + MOD) % MOD) * power(equa[i][piv[i]], MOD - 2, MOD) % MOD;
  }

  return true;
}

ll f(ll x) {
  ll re = 0, pw = 1;
  for (int i = 0; i < N; ++i, (pw *= x) %= MOD)
    (re += pw * sol[i] % MOD) %= MOD;
  return re;
}

int main() {
  ios::sync_with_stdio(false);

  for (int i = 0; i < N; ++i) {
    cout << "? " << i + 1 << endl;
    cin >> equa[i][N];
    equa[i][0] = 1;
    for (int j = 1; j < N; ++j)
      equa[i][j] = equa[i][j - 1] * (i + 1) % MOD;
  }

  gauss();

  int ans = -1;
  for (int i = 0; i < MOD; ++i)
    if (f(i) == 0) {
      ans = i;
      break;
    }
  cout << "! " << ans << endl;

  return 0;
}
