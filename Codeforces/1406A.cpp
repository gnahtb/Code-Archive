#include <bits/stdc++.h>

using namespace std;

int test, n, cnt[102];

int main() {
  cin >> test;
  while (test--) {
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i) {
      int a;
      cin >> a;
      ++cnt[a];
    }
    int mex1 = -1, mex2 = -1;
    bool flag = true;
    for (int i = 0; i <= 100; ++i) {
      if (cnt[i] > 1) {
        ++mex1;
        mex2 += flag;
      } else if (cnt[i] == 1) {
        ++mex1;
        flag = false;
      } else {
        break;
      }
    }
    // cout << mex1 << " " << mex2 << "\n";
    cout << (mex1 + mex2 + 2) << "\n";
  }
  return 0;
}