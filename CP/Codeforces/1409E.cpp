#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

const int N = 2e5 + 2;

int t, n, k, f[N];
pair<int, int> a[N];

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i].X;
    for (int i = 1; i <= n; ++i) cin >> a[i].Y;
    sort(a + 1, a + n + 1);
    for (int l = 1, r = 1; l <= n; ++l) {
      while (r <= n && a[r].X - a[l].X <= k) ++r;
      f[l] = r - l;
    }
    int fmax = 0, ans = 0;
    for (int l = n, r = n; l; --l) {
      while (r >= l + f[l]) {
        fmax = max(fmax, f[r]);
        --r;
      }
      int tmp = f[l] + fmax;
      ans = max(ans, tmp);
    }
    cout << ans << "\n";
  }
  return 0;
}