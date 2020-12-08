#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 2, K = 13;
const ll MOD = 1e9 + 7;

int q, n, cnt[1 << K];
bool prime[1 << K];
ll f[1 << K][2], pw2[N];

void Prep() {
  pw2[0] = 1;
  for (int i = 1; i < N; ++i)
    pw2[i] = pw2[i - 1] * 2 % MOD;
  for (int i = 2; i < 1 << K; ++i) {
    prime[i] = true;
    for (int j = 2; j * j <= i; ++j)
      if (i % j == 0) {
        prime[i] = false;
        break;
      }
  }
}

int main() {
  Prep();
  cin >> q;
  while (q--) {
    memset(cnt, 0, sizeof(cnt));
    memset(f, 0, sizeof(f));
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      ++cnt[a];
    }
    f[0][0] = 1;
    int it = 0;
    for (int i = 3500; i <= 4500; ++i) if (cnt[i] > 0) {
      for (int m = 0; m < 1 << K; ++m) {
        int evens = cnt[i] / 2 + 1, odds = cnt[i] - evens + 1;
        f[m][it ^ 1] = (f[m][it] * evens + f[m ^ i][it] * odds) % MOD;
      }
      it ^= 1;
    }
    ll ans = 0;
    for (int i = 0; i < 1 << K; ++i)
      if (prime[i]) (ans += f[i][it]) %= MOD;
    cout << ans << "\n";
  }
  return 0;
}