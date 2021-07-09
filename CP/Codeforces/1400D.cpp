#include <bits/stdc++.h>

using namespace std;

const int N = 3002;

int test, n, a[N], cnt[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin >> test;
  while (test--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    long long ans = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        ans += cnt[a[i]][a[j]];
      }
      for (int j = 1; j < i; ++j) {
        ++cnt[a[j]][a[i]];
      }
    }
    cout << ans << "\n";
  }
  return 0;
}