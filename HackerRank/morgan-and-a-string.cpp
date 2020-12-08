#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;
using ll = long long;

const int N = 10 + 2;
const ll BASE = 37, MOD[2] = {1957702511, 1000000007};

ll pw[N][2];

void Prep() {
  pw[0][0] = pw[0][1] = 1;
  for (int i = 1; i < N; ++i) {
    pw[i][0] = pw[i - 1][0] * BASE % MOD[0];
    pw[i][1] = pw[i - 1][1] * BASE % MOD[1];
  }
}

struct HashTable {
  ll tab[N][2];

  HashTable() {
    memset(tab, 0, sizeof(tab));
  }

  HashTable(string s) {
    memset(tab, 0, sizeof(tab));
    for (int i = 0; i < sz(s); ++i) {
      tab[i + 1][0] = (tab[i][0] * BASE + (s[i] - 'A' + 1)) % MOD[0];
      tab[i + 1][1] = (tab[i][1] * BASE + (s[i] - 'A' + 1)) % MOD[1];
    }
  }

  pair<ll, ll> GetHash(int l, int r) {
    ll v0 = (tab[r][0] - tab[l - 1][0] * pw[r - l + 1][0] % MOD[0] + MOD[0]) % MOD[0];
    ll v1 = (tab[r][1] - tab[l - 1][1] * pw[r - l + 1][1] % MOD[1] + MOD[1]) % MOD[1];
    return {v0, v1};
  }
} ha, hb;

int t;
string a, b;

int same_segment(int i, int j) {
  int l = 1, r = min(sz(a) - i + 1, sz(b) - j + 1), res = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    if (ha.GetHash(i, i + m - 1) == hb.GetHash(j, j + m - 1)) {
      res = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return res;
}

int main() {
  // freopen("inp.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  Prep();
  cin >> t;
  while (t--) {
    cin >> a >> b;
    int n = sz(a), m = sz(b);
    a += '[';
    b += "[";
    ha = HashTable(a);
    hb = HashTable(b);
    int i = 0, j = 0;
    string res = "";
    while (i < n || j < m) {
      if (i >= n) {
        res += b[j++];
      } else if (j >= m) {
        res += a[i++];
      } else {
        int pivot = same_segment(i + 1, j + 1);
        if (a[i + pivot] < b[j + pivot]) {
          res += a[i++];
        } else {
          res += b[j++];
        }
      }
    }
    cout << res << "\n";
  }
  return 0;
}