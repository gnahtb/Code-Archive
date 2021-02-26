#include <bits/stdc++.h>

using namespace std;

int n;

int ask(int i) {
  if (i < 1 || i > n) return INT_MAX;
  cout << "? " << i << endl;
  int ans;
  cin >> ans;
  return ans;
}

int main() {
  cin >> n;
  int l = 1, r = n;
  while (l <= r) {
    int m = (l + r) / 2;
    int a0 = ask(m - 1);
    int a1 = ask(m);
    int a2 = ask(m + 1);
    if (a0 < a1) {
      r = m - 1;
    } else if (a1 > a2) {
      l = m + 1;
    } else {
      cout << "! " << m << endl;
      return 0;
    }
  }
  return 0;
}
