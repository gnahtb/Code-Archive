#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int n, u[N], cnt[N], ans;
map<int, int> mp;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> u[i];
  int col = 0;
  for (int i = 1; i <= n; ++i) {
    if (cnt[u[i]] > 0) {
      --mp[cnt[u[i]]];
      if (mp[cnt[u[i]]] == 0) mp.erase(cnt[u[i]]);
    }
    col += cnt[u[i]] == 0;
    ++cnt[u[i]];
    ++mp[cnt[u[i]]];
    if (mp.size() == 1) {
      if (col == 1) ans = i;
      else if (mp.find(1) != mp.end()) ans = i;
    } else if (mp.size() == 2) {
      if (mp[cnt[u[i]]] == 1) {
        if (mp.find(cnt[u[i]] - 1) != mp.end()) ans = i;
        if (cnt[u[i]] == 1) ans = i;
      }
      if (mp[cnt[u[i]]] == col - 1) {
        if (mp.find(1) != mp.end()) ans = i;
        if (mp.find(cnt[u[i]] + 1) != mp.end()) ans = i;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
