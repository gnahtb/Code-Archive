#include <bits/stdc++.h>

using namespace std;

int t;
long long a, b, x, y, n;

int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> x >> y >> n;
    long long ta = max(a - (n - min(b - y, n)), x);
    long long tb = max(b - (n - min(a - x, n)), y);
    long long ans = min(ta * max(b - n, y), tb * max(a - n, x));
    cout << ans << "\n";
  }
  return 0;
}