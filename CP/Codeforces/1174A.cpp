#include <bits/stdc++.h>

using namespace std;

const int LIM = 2002;

int n, a[LIM];

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  n *= 2;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  long long suml = 0, sumr = 0;
  for (int i = 1; i <= n / 2; ++i) suml += a[i];
  for (int i = n; i > n / 2; --i) sumr += a[i];
  if (suml == sumr) {
    cout << "-1\n";
  } else {
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
  }
  return 0;
}
