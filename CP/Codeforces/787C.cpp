#include <bits/stdc++.h>

using namespace std;

const int N = 7002;

int n, k[2], s[2][N], clo[N][2], ans[N][2];
queue<pair<int, int>> q;

void Print() {
  for (int t = 0; t < 2; ++t) {
    for (int i = 1; i < n; ++i) {
      cout << (ans[i][t] == 1 ? "Win " : (ans[i][t] == 0 ? "Lose " : "Loop "));
    }
    cout << "\n";
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < 2; ++i) {
    cin >> k[i];
    for (int j = 0; j < k[i]; ++j) cin >> s[i][j];
  }
  memset(ans, -1, sizeof(ans));
  memset(clo, 0, sizeof(clo));
  ans[0][0] = ans[0][1] = 0;
  q.push({0, 0});
  q.push({0, 1});
  while (!q.empty()) {
    int i = q.front().first, j = q.front().second;
    q.pop();
    if (ans[i][j] == 0) {
      for (int it = 0; it < k[j ^ 1]; ++it) {
        int pre = (i - s[j ^ 1][it] + n) % n;
        if (ans[pre][j ^ 1] == -1) {
          ans[pre][j ^ 1] = 1;
          q.push({pre, j ^ 1});
        }
      }
    } else {
      for (int it = 0; it < k[j ^ 1]; ++it) {
        int pre = (i - s[j ^ 1][it] + n) % n;
        if (ans[pre][j ^ 1] == -1) {
          ++clo[pre][j ^ 1];
          if (clo[pre][j ^ 1] == k[j ^ 1]) {
            ans[pre][j ^ 1] = 0;
            q.push({pre, j ^ 1});
          }
        }
      }
    }
  }
  Print();
  return 0;
}
