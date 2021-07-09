#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll power(ll x, ll y, ll z) {
  if (!y) return 1 % z;
  ll t = power(x, y >> 1, z);
  (t *= t) %= z;
  if (y & 1) (t *= x) %= z;
  return t;
}

const int N = 2e5 + 2;
const ll MOD = 998244353;

int n; ll ans;

//{ solve 1
ll s1(int i, ll &fi) {
  if (i < 2) return 0;
  ll ret = (s1(i - 1, fi) * i % MOD + (ll)i * (i - 1) / 2 % MOD * fi % MOD) % MOD;
  (fi *= i) %= MOD;
  return ret;
}
//}

//{ solve 2
vector<pair<int, int>> v;
ll fen[N];
void upd(int x, int i) {
  for (; i <= n; i += i & -i) fen[i] += x;
}

ll sum(int i) {
  ll ret = 0;
  for (; i; i -= i & -i) ret += fen[i];
  return ret;
}

ll s2() {
  ll ret = 0;
  for (pair<int, int> i : v) {
    (ret += sum(i.second)) %= MOD;
    upd(1, i.second);
  }
  return ret;
}
//}

//{ solve 3
bool chk[N];
int m, pos[N], old[N], tmp[N];
//to the left of the unknown
ll s31() {
  ll ret = 0, cur = 0;
//  st.init(1, m);
  for (int i = n; i; --i)
    if (chk[i]) {
//      st.inc(pos[old[i]] + 1, m, 1);
      (cur += tmp[n] - tmp[old[i]]) %= MOD;
    }
    else (ret += cur) %= MOD;
  return ret;
}

//to the right of the unknown
ll s32() {
  ll ret = 0, cur = 0;
//  st.init(1, m);
  for (int i = 1; i <= n; ++i)
    if (chk[i]) {
//      st.inc(1, pos[old[i]], 1);
      (cur += tmp[old[i] - 1]) %= MOD;
    }
    else (ret += cur) %= MOD;
  return ret;
}
//}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1, t; i <= n; ++i) {
    cin >> t;
    tmp[i] = tmp[i - 1] + (t < 0);
    if (t > 0) {
      v.emplace_back(t, i);
      chk[t] = true;
      pos[i] = m;
      old[t] = i;
    } else pos[i] = ++m;
  }
  sort(v.begin(), v.end(), greater<pair<int, int>>());
  ll fn = 1;
  ans = s1(n - v.size(), fn);
  (ans += s2() * fn) %= MOD;
//  cout << tmp << "\n";
  if (n > v.size()) {
    ll co = fn * power(n - v.size(), MOD - 2, MOD) % MOD;
    (ans += (s31() + s32()) * co % MOD) %= MOD;
  }
  (ans *= power(fn, MOD - 2, MOD)) %= MOD;
  cout << ans << "\n";
  return 0;
}
