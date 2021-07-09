#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

#define fi first
#define se second

const int Lim = 1e5 + 2;

int n, m, a[Lim];
long long ans = 0;
ii op[Lim];

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  for (int i = 1; i <= m; ++i)
    cin >> op[i].se >> op[i].fi;
  sort(a + 1, a + n + 1);
  sort(op + 1, op + m + 1, greater<ii>());
  for (int i = 1, j = 1; i <= n; ++i) {
    if (!op[j].se) ++j;
    if (a[i] < op[j].fi) ans += op[j].fi, --op[j].se;
    else ans += a[i];
  }
  cout << ans << "\n";
  return 0;
}