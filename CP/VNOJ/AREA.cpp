#include <bits/stdc++.h>

using namespace std;

struct IntervalTree {
    const static int LIM = 2e5;
    struct Node {
        int il, ir, cnt = 0, len = 0;
    } a[LIM];

    void merge(Node &lhs, Node &rhs, Node &ret) {
        ret.len = lhs.len + rhs.len;
    }

#define mid ((l + r) >> 1)
#define nxt (i << 1)
    void build(int l, int r, int i = 1) {
        a[i].il = l; a[i].ir = r;
        if (l == r) return;
        build(l, mid, nxt);
        build(mid + 1, r, nxt + 1);
    }

    void inc(int l, int r, int x, int i = 1) {
        if (a[i].il > r || a[i].ir < l) return;
        if (l <= a[i].il && a[i].ir <= r) {
            a[i].cnt += x;
            if (a[i].cnt > 0)
                a[i].len = a[i].ir - a[i].il + 1;
            else
               	merge(a[nxt], a[nxt + 1], a[i]);
            return;
        }
        inc(l, r, x, nxt);
        inc(l, r, x, nxt + 1);
        if (a[i].cnt == 0)
            merge(a[nxt], a[nxt + 1], a[i]);
    }

    int query() {
        return a[1].len;
    }
#undef mid
#undef nxt
} it;

const int N_MAX = 10005, LIM = 30000;

int n, m = 0, ans = 0;
struct Entry { int t, x, yl, yr; } e[N_MAX << 1];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        e[++m] = {1, x1, y1, y2};
        e[++m] = {-1, x2, y1, y2};
    }
    sort(e + 1, e + m + 1, [](Entry &lhs, Entry &rhs) {
        return lhs.x == rhs.x ? lhs.t < rhs.t : lhs.x < rhs.x;
    });
    it.build(0, LIM);
    int pre = -1;
    for (int l = 1, r = 1; l <= m; pre = l, l = r) {
        while (r <= m && e[l].x == e[r].x) ++r;
        if (pre > 0) {
            int tmp = it.query();
            ans += tmp * (e[l].x - e[pre].x);
        }
        for (int i = l; i < r; ++i) it.inc(e[i].yl, e[i].yr - 1, e[i].t);
    }
    cout << ans << "\n";
    return 0;
}