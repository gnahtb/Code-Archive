#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define long long long

typedef pair<int, int> ii;

const int N_MAX = 2e5 + 5, T_MAX = 2e5 + 6, Ai_MAX = 1e6 + 5, BLK_SZ = 450;

int n, t, a[N_MAX], id[T_MAX], occur[Ai_MAX];
long ans[T_MAX];
ii q[T_MAX];

inline int block_id(int x) {
    return (x - 1) / BLK_SZ + 1;
}

bool cmp(int i1, int i2) {
    if (block_id(q[i1].fi) == block_id(q[i2].fi)) return q[i1].se < q[i2].se;
    return block_id(q[i1].fi) < block_id(q[i2].fi);
}

inline long e(int x, int y) {
    return (long)(x - y) * (x + y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= t; ++i)
        cin >> q[i].fi >> q[i].se, id[i] = i;
    sort(id + 1, id + t + 1, cmp);
    for (int i = 1, l = q[id[1]].fi, r = q[id[1]].fi - 1; i <= t; ++i) {
        ii cur = q[id[i]];
        long sol = ans[id[i - 1]];
        for (; l - 1 >= cur.fi; ++occur[a[l]])
            --l, sol += e(occur[a[l]] + 1, occur[a[l]]) * a[l];
        for (; l < cur.fi; --occur[a[l++]])
            sol -= e(occur[a[l]], occur[a[l]] - 1) * a[l];
        for (; r > cur.se; --occur[a[r--]])
            sol -= e(occur[a[r]], occur[a[r]] - 1) * a[r];
        for (; r + 1 <= cur.se; ++occur[a[r]])
            ++r, sol += e(occur[a[r]] + 1, occur[a[r]]) * a[r];
        ans[id[i]] = sol;
    }
    for (int i = 1; i <= t; ++i) cout << ans[i] << "\n";
    return 0;
}
