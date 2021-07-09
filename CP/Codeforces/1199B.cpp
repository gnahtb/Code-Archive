#include <iostream>

using namespace std;

double l, h;

int main() {
  cin >> h >> l;
  double ans = (l * l - h * h) / (h * 2.0);
  (cout << fixed).precision(10);
  cout << ans << endl;
}
