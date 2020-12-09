#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;
int n, ans[N];

int main() {
  cin >> n;
  int t = 0;
  for (int i = 2; i <= n; ++i) if (ans[i] == 0) {
    ++t;
    for (int j = i; j <= n; j += i)
      if (ans[j] == 0) ans[j] = t;
  }
  for (int i = 2; i <= n; ++i) cout << ans[i] << " ";
}
