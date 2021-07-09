#include <bits/stdc++.h>

using namespace std;

int n, a;
long long rem = 0, ans = 0;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    int tmp = min(rem, a / 2LL);
    rem -= tmp;
    a -= tmp * 2;
    tmp += a / 3;
    rem += a % 3;
    ans += tmp;
  }
  cout << ans << "\n";
  return 0;
}
