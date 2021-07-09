#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef int_fast64_t ll;
#define int int_fast32_t

const int n_max = 2e5 + 5, blk_sz = 500, blk_cnt = 500;

int n, q, a[n_max];
ll ans = 0;

int cnt;
vector<int> b[blk_cnt];

inline int block_id(int x) { return (x - 1) / blk_sz + 1; }
inline int block_left(int x) { return (x - 1) * blk_cnt + 1; }
inline int block_right(int x) { return min(x * blk_sz, n); }

inline int get_pos(int x, vector<int> &v) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

inline int get_cnt(int l, int r, vector<int> &v) {
    return upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
}

void init() {
    cnt = n / blk_cnt + (n % blk_cnt > 0);
    for (int j = 1; j <= cnt; ++j)
        for (int i = block_left(j); i <= block_right(j); ++i)
            a[i] = i, b[j].push_back(i);
}

int query(int vl, int vr, int il, int ir) {
    if (il > ir) return 0;
    int bl = block_id(il), br = block_id(ir), ret = 0;
    for (int i = il; i <= min(block_right(bl), ir); ++i)
        ret += vl <= a[i] && a[i] <= vr;
    for (int i = block_left(br); bl != br && i <= ir; ++i)
        ret += vl <= a[i] && a[i] <= vr;
    for (int i = bl + 1; i < br; ++i) ret += get_cnt(vl, vr, b[i]);
    return ret;
}

void update(int l, int r) {
    int bl = block_id(l), br = block_id(r);
    swap(b[bl][get_pos(a[l], b[bl])], b[br][get_pos(a[r], b[br])]);
    sort(b[bl].begin(), b[bl].end()); sort(b[br].begin(), b[br].end());
    if (a[l] < a[r]) ++ans; else --ans;
    ans += query(a[l] + 1, INT_MAX, l + 1, r - 1) - query(INT_MIN, a[l] - 1, l + 1, r - 1);
    ans -= query(a[r] + 1, INT_MAX, l + 1, r - 1) - query(INT_MIN, a[r] - 1, l + 1, r - 1);
    swap(a[l], a[r]);
}

int main() {
    ios::sync_with_stdio(false);
    scanf("%d%d", &n, &q);
    init();
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l > r) swap(l, r);
        if (l != r) update(l, r);
        printf("%lld\n", ans);
    }
    return 0;
}
