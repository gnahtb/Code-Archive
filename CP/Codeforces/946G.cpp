#include <bits/stdc++.h>

#define fi first
#define se second
#define sz(a) (int)a.size()

using namespace std;
using ii = pair<int, int>;

const int oo = 2e9;
const int N = 2e5 + 2;

int n, a[N], b[N], f[2][N], ans;
vector<int> v;
priority_queue<ii, vector<ii>> q[N];

int e[N];
void LIS(int s, int t, int d, int (&z)[N]) {
  fill(e + 1, e + n + 1, oo);
  e[0] = -oo;
  for (int i = s; i != t + d; i += d) {
    int l = 0, r = n;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (b[i] >= e[m]) z[i] = l = m + 1;
      else r = m - 1;
    }
    e[z[i]] = min(e[z[i]], b[i]);
  }
}

inline int idx(int x) {
  return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

inline int pos(int x) {
  return upper_bound(v.begin(), v.end(), x) - v.begin();
}

struct SegmentTree {
  struct Node { int l, r, v; } a[N << 2];

#define md ((l + r) >> 1)
#define nx (i << 1)
  void init(int l, int r, int i = 1) {
    a[i].l = l;
    a[i].r = r;
    a[i].v = -oo;
    if (l == r) return;
    init(l, md, nx);
    init(md + 1, r, nx + 1);
  }

  void upd(int p, int x, int i = 1) {
    if (a[i].l > p || a[i].r < p) return;
    if (a[i].l == p && a[i].r == p) {
      a[i].v = x;
      return;
    }
    upd(p, x, nx);
    upd(p, x, nx + 1);
    a[i].v = max(a[nx].v, a[nx + 1].v);
  }

  int fmx(int l, int r, int i = 1) {
    if (a[i].l > r || a[i].r < l) return -oo;
    if (l <= a[i].l && a[i].r <= r) return a[i].v;
    return max(fmx(l, r, nx), fmx(l, r, nx + 1));
  }
#undef md
#undef nx
} st;

int main() {
  ios::sync_with_stdio(false);
//   freopen("inp.txt", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  for (int i = n; i; --i) b[i] = i - a[i];
  LIS(n, 1, -1, f[1]);
  for (int i = 1; i <= n; ++i) b[i] = a[i] - i;
  LIS(1, n, 1, f[0]);

  for (int i = 1; i <= n; ++i) ans = max(ans, f[0][i]);
  if (ans < n) ++ans;
  ans = n - ans;

  if (ans == 0) {
    cout << "0\n";
    return 0;
  }

  for (int i = 1; i <= n; ++i) v.push_back(b[i]);
  v.push_back(INT_MAX);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  st.init(1, sz(v));
  for (int i = 1; i < n; ++i) q[idx(b[i])].emplace(f[0][i], i);
  for (int i = 1; i <= sz(v); ++i) {
    q[i].emplace(INT_MIN, 0);
    st.upd(i, q[i].top().fi);
  }

  for (int i = n; i; --i) {
    if (i > 1) {
      int pt = idx(b[i - 1]);
      while (q[pt].top().se >= i - 1) q[pt].pop();
      st.upd(pt, q[pt].top().fi);
    }

    int tmp = st.fmx(1, pos(b[i] + 1));
    ans = min(ans, n - 1 - tmp - f[1][i]);
  }
  cout << ans << "\n";
  return 0;
}
