#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll a, b, ans = 0;
    cin >> a >> b;
    for (ll k = 1; k * k < a; ++k) {
      ans += max(min((a - k) / k, b) - k, 0LL);
    }
    cout << ans << "\n";
  }
  return 0;
}
