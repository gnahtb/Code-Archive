#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int ans = INT_MAX;
    int tmp = 0;
    int limb = b + 1000000;
    for (; b <= limb; ++b, ++tmp) {
      if (b == 1) continue;
      int cnt = tmp;
      int tmp1 = a;
      while (tmp1 > 0) {
        tmp1 /= b;
        ++cnt;
      }
      ans = min(ans, cnt);
    }
    cout << ans << "\n";
  }
  return 0;
}
