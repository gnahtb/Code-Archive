#include <bits/stdc++.h>

using namespace std;

#define long long long
#define sz(a) (int)a.size()
#define fi first
#define se second

typedef pair<int, int> ii;

const int n_max = 2e5 + 5, lg_max = 19;
struct TSuffixArray {
    struct Entry {
        int x, y, z;
        bool operator <(Entry &e) { return x == e.x ? y < e.y : x < e.x; }
        bool operator ==(Entry &e) { return x == e.x && y == e.y; }
    } C[n_max];
    int n, P[lg_max][n_max];

    void build(int sz, char *s) {
        n = sz;
        for (int i = 1; i <= n; ++i) P[0][i] = s[i - 1] - 'a' + 1;
        for (int j = 1, l = 1; j <= __lg(n); ++j, l <<= 1) {
            for (int i = 1; i <= n; ++i)
                C[i] = {P[j - 1][i], i + l <= n ? P[j - 1][i + l] : -1, i};
            sort(C + 1, C + n + 1);
            for (int i = 1; i <= n; ++i)
                P[j][C[i].z] = (i && C[i] == C[i - 1]) ? P[j][C[i - 1].z] : i;
        }
    }

    int get_lcp(int x, int y) {
        int z = 0;
        for (int i = __lg(n), l = 1 << i; i >= 0; --i, l >>= 1)
            if (max(x, y) + l - 1 <= n && P[i][x] == P[i][y])
                x += l, y += l, z += l;
        return z;
    }
} t;

int n, q;
char s[n_max];

int k;
ii a[n_max << 1];
vector<ii> st;
long solve(int x, int y, int z) {
    long ret = 0, cur = 0;
    st.clear();
    for (int i = x; i != y + z; i += z) {
        if (!st.empty()) {
            int tmp = t.get_lcp(a[i - z].fi, a[i].fi), cnt = 0;
            while (!st.empty() && st.back().fi >= tmp) {
                cnt += st.back().se;
                cur -= (long)st.back().fi * st.back().se;
                st.pop_back();
            }
            st.push_back({tmp, cnt});
            cur += (long)tmp * cnt;
        }
        if (a[i].se) {
            st.push_back({INT_MAX, 1});
            cur += INT_MAX;
        } else ret += cur;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    scanf("%d%d\n%s", &n, &q, &s);
    t.build(n, s);
    while (q--) {
        int l;
        scanf("%d%d", &k, &l);
        for (int i = 1; i <= k; ++i)
            scanf("%d", &a[i].fi), a[i].se = 0;
        for (int i = 1; i <= l; ++i)
            scanf("%d", &a[k + i].fi), a[k + i].se = 1;
        k += l;
        sort(a + 1, a + k + 1, [](ii &x, ii &y) {
            int l = __lg(t.n);
            if (t.P[l][x.fi] == t.P[l][y.fi]) {
                return x.fi == y.fi ? x.se < x.se : x.fi < y.fi;
            } else return t.P[l][x.fi] < t.P[l][y.fi];
        });
        printf("%lld\n", solve(1, k, 1) + solve(k, 1, -1));
    }
    return 0;
}
