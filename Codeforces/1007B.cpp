#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline int bit(int b, int i) {
  return b >> i & 1;
}

struct Triplet {
  int a[3];

  Triplet(int _x = 0, int _y = 0, int _z = 0) {
    a[0] = _x;
    a[1] = _y;
    a[2] = _z;
  }

  int& operator [](int i) {
    return a[i];
  }

  inline void sync() {
    sort(a, a + 3);
  }
};

istream& operator >>(istream &in, Triplet &tri) {
  in >> tri[0] >> tri[1] >> tri[2];
  return in;
}

ostream& operator <<(ostream &out, Triplet &tri) {
  out << tri[0] << " " << tri[1] << " " << tri[2] << "\n";
  return out;
}

bool check(Triplet &x) {
  vector<int> p = {0, 1, 2};
  do {
    bool flag = true;
    for (int i = 0; i < 3; ++i)
      if (!bit(x[i], p[i])) {
        flag = false;
        break;
      }
    if (flag) return true;
  } while (next_permutation(p.begin(), p.end()));
  return false;
}

vector<Triplet> v;
void gen_triplet() {
  for (int i = 1; i < 8; ++i)
    for (int j = i; j < 8; ++j)
      for (int k = j; k < 8; ++k) {
        Triplet t(i, j, k);
        if (check(t)) v.push_back(t);
      }
}

const int LIM = 1e5;
ll dv[LIM + 2];

void gen_div() {
  for (int n = 1; n <= LIM; ++n) {
    for (int i = 1; i * i <= n; ++i) {
      if (!(n % i)) {
        ++dv[n];
        if (i * i < n) ++dv[n];
      }
    }
  }
}

//inline int enc(int x, Triplet& t) {
//  int r = 0;
//  for (int i = 0; i < 3; ++i)
//    if (!(t[i] % x)) r += 1 << i;
//  return r;
//}

ll cnt[8];
ll calc(Triplet &x) {
  if (x[0] == x[1] && x[1] == x[2])
    return cnt[x[0]] * (cnt[x[0]] + 1) * (cnt[x[0]] + 2) / 6;
  else if (x[0] == x[1]) {
    ll tmp = ((cnt[x[0]] + 1) * cnt[x[0]]) >> 1;
    return tmp * cnt[x[2]];
  } else if (x[1] == x[2]) {
    ll tmp = ((cnt[x[1]] + 1) * cnt[x[1]]) >> 1;
    return tmp * cnt[x[0]];
  } else return cnt[x[0]] * cnt[x[1]] * cnt[x[2]];
}

#define sz(a) (int)a.size()
ll solve(Triplet &x) {
  ll ret = 0;
  memset(cnt, 0, sizeof cnt);
//  dt.clear();
//  for (int i = 0; i < 3; ++i)
//    for (int j : dv[x[i]]) dt.insert(j);
//  for (int i : dt) ++cnt[enc(i, x)];
  ll g1 = __gcd(x[0], __gcd(x[1], x[2]));
  ll g2 = __gcd(x[0], x[1]);
  ll g3 = __gcd(x[1], x[2]);
  ll g4 = __gcd(x[0], x[2]);
  cnt[7] = dv[g1];
  cnt[3] = dv[g2] - cnt[7];
  cnt[6] = dv[g3] - cnt[7];
  cnt[5] = dv[g4] - cnt[7];
  cnt[1] = dv[x[0]] - cnt[7] - cnt[3] - cnt[5];
  cnt[2] = dv[x[1]] - cnt[7] - cnt[3] - cnt[6];
  cnt[4] = dv[x[2]] - cnt[7] - cnt[6] - cnt[5];

  for (Triplet &i : v) ret += calc(i);
  return ret;
}

map<tuple<int, int, int>, int> pre_ans;
int main() {
  ios::sync_with_stdio(false);
//   freopen("inp.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
  gen_div();
  gen_triplet();
//  cout << v.size() << "\n";
  int test;
  cin >> test;
  while (test--) {
    Triplet x;
    cin >> x;
    x.sync();
    tuple<int, int, int> tmp = make_tuple(x[0], x[1], x[2]);
    if (pre_ans.find(tmp) == pre_ans.end())
      pre_ans[tmp] = solve(x);
    cout << pre_ans[tmp] << "\n";
  }
  return 0;
}
