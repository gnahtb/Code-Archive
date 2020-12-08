#include <bits/stdc++.h>

using namespace std;

int t, n, x, y;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> x >> y;
    int d = -1;
    for (int i = 1; i * i <= y - x; ++i)
      if ((y - x) % i == 0) {
        if (i < n) d = max(d, i);
        if ((y - x) / i < n) d = max(d, (y - x) / i);
      }
    d = (y - x) / d;
    vector<int> ans;
    for (int i = x; i <= y; i += d) {
      ans.push_back(i);
    }
    int cur = x - d;
    while (cur > 0 && (int)ans.size() < n) {
      ans.push_back(cur);
      cur -= d;
    }
    cur = y;
    while ((int)ans.size() < n) {
      cur += d;
      ans.push_back(cur);
    }
    for (int i : ans) cout << i << " ";
    cout << "\n";
  }
  return 0;
}