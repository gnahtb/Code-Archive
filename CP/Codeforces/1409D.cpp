#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

int t, s;
long long n;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> s;
    string sn = to_string(n);
    int cur = 0;
    for (int i = 0; i < sz(sn); ++i) cur += sn[i] - '0';
    if (cur <= s) {
      cout << "0\n";
      continue;
    }
    int digits = sz(sn);
    long long tmp = 1;
    for (int i = 0; i < digits; ++i) tmp *= 10;
    long long ans = tmp - n;
    for (int i = sz(sn) - 1; i >= 0; --i) {
      cur = 0;
      bool flag = false;
      for (int j = 0; j < i; ++j) cur += sn[j] - '0';
      for (int j = sn[i] - '0' + 1; j < 10; ++j) {
        if (cur + j <= s) {
          flag = true;
          long long sc = 0;
          for (int k = 0; k < i; ++k) sc = sc * 10 + sn[k] - '0';
          (sc *= 10) += j;
          while (sz(to_string(sc)) < sz(sn)) sc *= 10;
          ans = sc - n;
          break;
        }
      }
      if (flag) break;
    }
    cout << ans << "\n";
  }
  return 0;
}