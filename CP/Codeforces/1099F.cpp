#include <bits/stdc++.h>

#define fi first
#define se second
#define sz(a) (int)a.size()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 2;

struct FenwickTree {
  ll a[N];

  FenwickTree() { memset(a, 0, sizeof a); }

  inline void inc(int i, ll x) {
    for (; i < N; i += i & -i) a[i] += x;
  }

  inline ll sum(int i) {
    ll r = 0;
    for (; i; i -= i & -i) r += a[i];
    return r;
  }
} ts, qs;


int n, x[N], t[N];
ll T;
vector<int> vt;
vector<pii> ad[N];

ll v[N], f[N];

inline int get_idx(int x) {
  return (lower_bound(vt.begin(), vt.end(), x) - vt.begin()) + 1;
}

void dfs(int u, ll cd = 0) {
  int tmp = get_idx(t[u]);
  if (tmp >= N) exit(t[u]);
  ts.inc(tmp, (ll)x[u] * t[u]);
  qs.inc(tmp, x[u]);

  ll mx1 = LLONG_MIN, mx2 = LLONG_MIN;
  for (pii i : ad[u]) {
    dfs(i.fi, cd + (ll)i.se);

    if (f[i.fi] > mx1) {
      mx2 = mx1;
      mx1 = f[i.fi];
    } else if (f[i.fi] > mx2) mx2 = f[i.fi];
  }

  int lf = 0, rg = sz(vt), re1 = -1, re2 = -1;
  while (lf <= rg) {
    int md = (lf + rg) >> 1;
    if (ts.sum(md) <= T - cd * 2)
      re1 = md, lf = md + 1;
    else
      rg = md - 1;
  }

  lf = 0, rg = sz(vt);
  while (lf <= rg) {
    int md = (lf + rg) >> 1;
    if (ts.sum(md) > T - cd * 2)
      re2 = md, rg = md - 1;
    else
      lf = md + 1;
  }

  if (re1 > 0)
    v[u] = qs.sum(re1);
  if (re2 > 0)
    v[u] += (T - cd * 2 - ts.sum(re1)) / vt[re2 - 1];
  f[u] = max(v[u], mx2);
  if (u == 1) f[u] = max(f[u], mx1);

  ts.inc(tmp, -(ll)x[u] * t[u]);
  qs.inc(tmp, -x[u]);
}

int main() {
  ios::sync_with_stdio(false);
//   freopen("inp.txt", "r", stdin);
  cin >> n >> T;
  for (int i = 1; i <= n; ++i) cin >> x[i];
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    vt.push_back(t[i]);
  }
  sort(vt.begin(), vt.end());
  vt.erase(unique(vt.begin(), vt.end()), vt.end());
//  cout << sz(vt) << "\n";
//  for (int i : vt) cout << i << "\n";
  for (int i = 2; i <= n; ++i) {
   int p, l;
   cin >> p >> l;
   ad[p].emplace_back(i, l);
  }
  dfs(1);
//  for (int i = 1; i <= n; ++i) cout << v[i] << " ";
//  cout << endl;
//  for (int i = 1; i <= n; ++i) cout << f[i] << " ";
  cout << f[1] << "\n";
  return 0;
}
