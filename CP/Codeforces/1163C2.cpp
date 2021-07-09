#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;

const int N = 1002;

int n;
ll ans = 0;
ld x[N], y[N];
set<pair<ld, ld>> st;
map<ld, ll> cnt;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
  ll sum = 0;
  for (int i = 1; i < n; ++i)
    for (int j = i + 1; j <= n; ++j) {
      ld a, b;
      if (x[i] == x[j]) {
        a = INT_MAX;
        b = x[i];
      } else {
        a = (y[i] - y[j]) / (x[i] - x[j]);
        b = y[i] - a * x[i];
      }
      st.emplace(a, b);
    }
  for (pair<ld, ld> i : st)
    ++cnt[i.first];
  for (pair<ld, ld> i : st) {
    ans += st.size() - cnt[i.first];
  }
  ans /= 2LL;
  cout << ans << "\n";
  return 0;
}
