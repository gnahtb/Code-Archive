#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int SUM = 3e5, LEN = __lg(SUM) + 2;
const ll oo = 1e16;

ll cnt[SUM][LEN][2], sumcnt[SUM];

void Prep() {
  memset(cnt, 0, sizeof(cnt));
  cnt[0][0][1] = cnt[0][1][0] = 1;
  for (int sum = 0; sum < SUM - 1; ++sum) {
    if (sum > 0)
      sumcnt[sum] = sumcnt[sum - 1];
    for (int len = 0; len < LEN; ++len) {
      sumcnt[sum] += cnt[sum][len][0];
      for (int d = 0; d < 10; ++d) {
        int new_sum = sum + d * (1 << len);
        if (new_sum < SUM && len + 1 < LEN) {
          cnt[new_sum][len +  1][1] = min(cnt[new_sum][len + 1][1] + cnt[sum][len][1], oo);
          if (d == 0) continue;
          cnt[new_sum][len +  1][0] = min(cnt[new_sum][len + 1][0] + cnt[sum][len][1], oo);
        }
      }
    }
  }
}

string Solve(ll x) {
  int l = 0, r = SUM - 2, pivot = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    if (sumcnt[m] < x) {
      pivot = l = m + 1;
    } else {
      r = m - 1;
    }
  }
  if (pivot) x -= sumcnt[pivot - 1];
  int len = 0;
  for (; len < LEN; ++len)
    if (x > cnt[pivot][len][0]) x -= cnt[pivot][len][0];
    else break;
  string res = "";
  bool leading = true;
  for (; len; --len) {
    for (int d = leading && len > 1; d < 10; ++d) {
      int rem = pivot - d * (1 << (len - 1));
      if (x > cnt[rem][len - 1][1]) {
        x -= cnt[rem][len - 1][1];
      } else {
        res += '0' + d;
        pivot -= d * (1 << (len - 1));
        break;
      }
    }
    leading = false;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  Prep();
  int q;
  cin >> q;
  while (q--) {
    ll x;
    cin >> x;
    string ans = Solve(x);
    cout << ans << "\n";
  }
  return 0;
}