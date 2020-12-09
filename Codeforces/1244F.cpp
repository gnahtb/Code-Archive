#include <bits/stdc++.h>

#define fi first
#define se second
#define sz(a) (int)a.size()

using namespace std;
using pii = pair<int, int>;

struct Data {
    int l, r, c;
    Data(int _l, int _r, int _c) {
        l = _l; r = _r; c = _c;
    }
};

int n, k;
string s;

// black = 1
// white = 0
vector<Data> v;
vector<pii> sm;

inline char get_code(int x) {
    return x == 0 ? 'W' : 'B';
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k >> s;
    for (int l = 0, r = 0; l < n; l = r) {
        while (r < n && s[l] == s[r]) ++r;
        v.emplace_back(l, r - 1, s[l] == 'B');
    }
    if (sz(v) > 1 && v.front().c == v.back().c) {
        v.front().l = v.back().l;
        v.pop_back();
    }
    int cnt_tmp = 0;
    for (int i = 0; i < sz(v); ++i)
        if (v[i].l != v[i].r) ++cnt_tmp;
    if (cnt_tmp == 0) {
        if (k % 2 == 0) {
            cout << s << "\n";
            return 0;
        } else {
            for (char i : s) {
                cout << (i == 'B' ? 'W' : 'B');
            }
            cout << "\n";
            return 0;
        }
    } else {
        for (int i = 0; i < sz(v); ++i) {
            if (v[i].l == v[i].r) continue;
            int j = i + 1;
            bool flag = false;
            if (j == sz(v)) {
                flag = true;
                j = 0;
            }
            while (v[j].l == v[j].r) {
                ++j;
                if (j == sz(v)) {
                    flag = true;
                    j = 0;
                }
            }
            int ki = (i + 1) % sz(v);
            while (ki != j) {
                int t1 = (v[ki].l - v[i].r + n) % n;
                int t2 = (v[j].l - v[ki].l + n) % n;
                int tp = min(t1, t2);
                if (tp <= k) s[v[ki].l] = get_code(v[t1 < t2 ? i : j].c);
                else s[v[ki].l] = k % 2 == 0 ? get_code(v[ki].c) : get_code(v[ki].c ^ 1);
                (++ki) %= sz(v);
            }
            if (flag) break;
            i = j - 1;
        }
        for (int i = 0; i < sz(v); ++i) {
            if (v[i].l == v[i].r) continue;
            int k = v[i].l;
            while (true) {
                s[k] = get_code(v[i].c);
                if (k == v[i].r) break;
                (++k) %= n;
            }
        }
        cout << s << "\n";
    }
    return 0;
}
