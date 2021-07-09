#include <bits/stdc++.h>

using namespace std;

int n, m, c, ans;
vector<pair<int, int>> a;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int l, r;
    cin >> l >> r;
    a.emplace_back(l, 1);
    a.emplace_back(r + 1, -1);
  }
  sort(a.begin(), a.end());
  for (int i = 1, j = 0; i <= n; ++i) {
    while (j < a.size() && a[j].first <= i)
      c += a[j++].second;
    if (c == m) ++ans;
  }
  cout << ans << "\n";
  return 0;
}