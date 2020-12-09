#include <bits/stdc++.h>

using namespace std;

const int X = 18;

int n, x;
bool chk[1 << X];
vector<int> ans;

int main() {
  cin >> n >> x;
  int cur = 0, nxt = (1 << n) - 1;
  chk[0] = chk[x] = true;
  while (true) {
    while (nxt >= 0 && chk[nxt]) --nxt;
    if (nxt < 0) break;
    ans.push_back(nxt ^ cur);
    chk[nxt] = chk[nxt ^ x] = true;
    cur = nxt;
  }
  cout << ans.size() << "\n";
  for (int i : ans) cout << i << " ";
  return 0;
}
