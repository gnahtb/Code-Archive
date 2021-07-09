#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

struct SuffixArray {
    vector<vector<int>> c;

    SuffixArray() {
        c.clear();
    }

    vector<int> Build(string s) {
#define n sz(s)
        vector<int> cnt, p;
        c.resize(__lg(n) + 1);
        c[0].resize(n);
        cnt.assign(max(n, 256) + 2, 0);
        p.resize(n, 0);
        for (int i = 0; i < n; ++i)
            ++cnt[s[i]];
        for (int i = 1; i < sz(cnt); ++i)
            cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; ++i)
            p[--cnt[s[i]]] = i;
        c[0][p[0]] = 0;
        for (int i = 1; i < n; ++i)
            c[0][p[i]] = c[0][p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
        for (int j = 1; j <= __lg(n); ++j) {
            cnt.assign(max(n, 256) + 2, 0);
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
#undef n
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
};

int main() {
    freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test--) {
        string s;
        long long k;
        cin >> s >> k;
        s += "$";
        SuffixArray sufarr = SuffixArray();
        vector<int> p = sufarr.Build(s);
        p.erase(p.begin());
        for (int i = 0; i < sz(p); ++i) {
            int t = sz(p) - p[i];
            if (i > 0) {
                int lcp = sufarr.LCP(p[i], p[i - 1]);
                t -= lcp;
            }
            long long tk = 1LL * (sz(p) - p[i] + sz(p) - p[i] - t + 1) * t / 2;
            if (tk < k) {
                k -= tk;
            } else {
                int curlen = sz(p) - p[i] - t + 1;
                while (k > curlen && p[i] + curlen <= sz(p)) {
                    k -= curlen;
                    ++curlen;
                }
                cout << s[p[i] + k - 1] << "\n";
                break;
            }
        }
    }
    return 0;
}