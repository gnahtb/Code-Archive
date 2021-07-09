#include <bits/stdc++.h>

#define p4(a) (a) * (a) * (a) * (a)

using namespace std;

const int N = 502;

int n, m, a[N][N];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if ((i + j) % 2 == 0) {
        cout << "720720 ";
      } else {
        cout << (720720 + p4(a[i][j])) << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}