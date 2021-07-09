#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int n, m, k;
ll ans;

ll power(ll x, ll y, ll z) {
  if (!y) return 1 % z;
  ll t = power(x, y >> 1, z);
  (t *= t) %= z;
  if (y & 1) (t *= x) %= z;
  return t;
}

ll f(int x) {
  if (x < 2) return 1;
  return f(x - 1) * x % MOD;
}

ll nCr(int n, int r) {
  ll ret = f(n);
  ll denom1 = power(f(r), MOD - 2, MOD);
  ll denom2 = power(f(n - r), MOD - 2, MOD);
  (ret *= denom1 * denom2 % MOD) %= MOD;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      ll tmp = (ll)m * (1 + n - i) * (n - i) / 2 % MOD;
      (tmp += (ll)(i - 1) * j * (j - 1) / 2) %= MOD;
      (tmp += (ll)i * (1 + m - j) * (m - j) / 2) %= MOD;
      (ans += tmp) %= MOD;
    }
  (ans *= nCr(n * m - 2, k - 2)) %= MOD;
  cout << ans << "\n";
  return 0;
}