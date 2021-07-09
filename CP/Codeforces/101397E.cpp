#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

const int lim = 6005, lg_max = 13;

struct SuffixArray {
    vector<vector<int>> c;

    SuffixArray() {
        c.clear();
    }

    vector<int> Build(int n, int* a) {
        vector<int> s, cnt, p;
        s.resize(n);
        for (int i = 0; i < n; ++i) s[i] = a[i + 1];
        c.resize(__lg(n) + 1);
        c[0].resize(n);
        cnt.assign(max(n, 3000) + 2, 0);
        p.resize(n, 0);
        for (int i = 0; i < n; ++i) ++cnt[s[i]];
        for (int i = 1; i < sz(cnt); ++i) cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; ++i) p[--cnt[s[i]]] = i;
        c[0][p[0]] = 0;
        for (int i = 1; i < n; ++i)
            c[0][p[i]] = c[0][p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
        for (int j = 1; j <= __lg(n); ++j) {
            cnt.assign(max(n, 3000) + 2, 0);
            vector<int> p1(n);
            for (int i = 0; i < n; ++i)
                p1[i] = (p[i] - (1 << (j - 1)) + n) % n;
            for (int i = 0; i < n; ++i)
                ++cnt[c[j - 1][p1[i]]];
            for (int i = 1; i < sz(cnt); ++i)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; --i)
                p[--cnt[c[j - 1][p1[i]]]] = p1[i];
            c[j].resize(n);
            c[j][p[0]] = 0;
            for (int i = 1; i < n; ++i) {
                pair<int, int> cur = {c[j - 1][p[i]], c[j - 1][(p[i] + (1 << (j - 1))) % n]};
                pair<int, int> pre = {c[j - 1][p[i - 1]], c[j - 1][(p[i - 1] + (1 << (j - 1))) % n]};
                c[j][p[i]] = c[j][p[i - 1]] + (cur != pre);
            }
        }
        return p;
    }

    int LCP(int x, int y) {
#define n sz(c[0])
        int z = 0;
        for (int j = __lg(n); j >= 0; --j) {
            if (c[j][x] == c[j][y]) {
                z += 1 << j;
                x += 1 << j;
                y += 1 << j;
            }
        }
        return z;
#undef n
    }
} t;

int m, n, k, a[lim], b[lim], ta[lim], tb[lim], tc[lim], tu[lim], ans[lim];
deque<int> dq;

void find_seq(int x, int cnt, int *seq, int *ret) {
    dq.clear();
    int cur = 0, i = 1;
    while (x) {
        while (!dq.empty() && dq.front() <= ret[cur]) dq.pop_front();
        for (; i <= cnt - x + 1; ++i) {
            while (!dq.empty() && seq[dq.back()] > seq[i]) dq.pop_back();
            dq.push_back(i);
        }
        ret[++cur] = dq.front();
        --x;
    }
    for (int i = 1; i <= cur; ++i) ret[i] = seq[ret[i]];
}

void solve() {
    memset(ans, -1, sizeof ans);
    for (int i = 1; i <= min(m, k); ++i) {
        if (k - i > n || k - i < 1) continue;
        find_seq(i, m, a, ta);
        find_seq(k - i, n, b, tb);
        for (int j = 1; j <= i; ++j) tc[j] = ta[j];
        for (int j = 1; j <= k - i; ++j) tc[i + j + 1] = tb[j];
        ta[i + 1] = tb[k - i + 1] = tc[i + 1] = tc[k + 2] = 3001;
        t.Build(k + 2, tc);
        int ia = 1, ib = 1;
        for (int j = 1; j <= k; ++j) {
            bool flag = false;
            if (ia > i) flag = true;
            else if (ib <= k - i) {
                if (ta[ia] > tb[ib]) flag = true;
                else if (ta[ia] == tb[ib]) {
                    int l = t.LCP(ia - 1, ib + i);
                    if (ta[ia + l] > tb[ib + l]) flag = true;
                }
            }
            if (flag) tu[j] = tb[ib++]; else tu[j] = ta[ia++];
        }
        if (ans[1] == -1) {
            for (int j = 1; j <= k; ++j)
                ans[j] = tu[j];
        } else {
            bool flag = true;
            for (int j = 1; j <= k; ++j) {
                if (ans[j] < tu[j]) { flag = false; break; }
                if (ans[j] > tu[j]) break;
            }
            if (flag)
                for (int j = 1; j <= k; ++j)
                    ans[j] = tu[j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    freopen("inp.txt", "r", stdin);
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> b[i];
    cin >> k;
    solve();
    for (int i = 1; i <= k; ++i) cout << ans[i] << " ";
    return 0;
}