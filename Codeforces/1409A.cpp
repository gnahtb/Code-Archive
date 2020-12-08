#include <bits/stdc++.h>

using namespace std;

int t, a, b;

int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b;
    int d = (abs(b - a) + 9) / 10;
    cout << d << "\n";
  }
  return 0;
}