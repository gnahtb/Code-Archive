#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
  cin >> n >> m;
  if (m == 0) {
    cout << "1\n";
    return 0;
  }
  if (m <= n / 2) {
    cout << m << "\n";
    return 0;
  }
  cout << (n / 2 + n % 2) - (m - n / 2) << "\n";
  return 0;
}
