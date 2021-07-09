#include <bits/stdc++.h>

using namespace std;

int n, x, y, a[100002];

int main() {
  cin >> n >> x >> y;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    bool chk = true;
    for (int j = max(1, i - x); j < i; ++j)
      if (a[i] >= a[j]) {
        chk = false;
        break;
      }
    for (int j = i + 1; j <= min(n, i + y); ++j)
      if (a[i] >= a[j]) {
        chk = false;
        break;
      }
    if (chk) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
