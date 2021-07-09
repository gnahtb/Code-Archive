#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 2;

int n, q, k, a[N];
ll b[N];

ll f(int l, int r) {
  if (a[r] > k) return 0;
  if (l == r) return k - 1;
  ll sum = b[r - 1] - b[l];
  sum += a[l + 1] - 2;
  sum += k - a[r - 1] - 1;
  return sum;
}

int main() {
  cin >> n >> q >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    if (i > 1) b[i] += a[i] - a[i - 1] - 1;
    if (i < n) b[i] += a[i + 1] - a[i] - 1;
    // cerr << b[i] << "\n";
    b[i] += b[i - 1];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << f(l, r) << "\n";
  }
  return 0;
}
