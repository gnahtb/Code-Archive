#include <bits/stdc++.h>

using namespace std;

int n, a[100002];

int main() {
  cin >> n;
  bool chk[2];
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    chk[a[i] % 2] = true;
  }
  if (chk[0] && chk[1]) sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) cout << a[i] << " ";
  return 0;
}
