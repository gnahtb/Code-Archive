#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int q;
ll sb = 0;

//heap max - min
ll sl, sr;
priority_queue<int, vector<int>> ql;
priority_queue<int, vector<int>, greater<int>> qr;

int main() {
  ios::sync_with_stdio(false);
  cin >> q;
  ql.push(INT_MIN);
  qr.push(INT_MAX);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, b;
      cin >> a >> b;
      sb += b;
      if (a <= qr.top()) {
        ql.push(a);
        sl += a;
      } else {
        qr.push(a);
        sr += a;
      }
      while (ql.size() > qr.size() + 1) {
        qr.push(ql.top());
        sr += ql.top();
        sl -= ql.top();
        ql.pop();
      }
      while (ql.size() < qr.size()) {
        ql.push(qr.top());
        sl += qr.top();
        sr -= qr.top();
        qr.pop();
      }
    } else {
      ll x = ql.top();
      ll mv = x * (ql.size() - qr.size()) - sl + sr + sb;
      cout << x << " " << mv << "\n";
    }
  }
  return 0;
}