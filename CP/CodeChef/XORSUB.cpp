#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

const int N_MAX = 1005, LG_MAX = 10;

int test, n, k, a[N_MAX];
vector<bitset<N_MAX>> equa;

inline int bit(int b, int i) {
    return b >> i & 1;
}

inline void build(int y) {
    equa.clear();
    for (int j = LG_MAX; j >= y; --j) {
        bitset<N_MAX> tmp;
        for (int i = 0; i <= n; ++i)
            tmp[i] = bit(a[i], j);
        equa.push_back(tmp);
    }
}

bool gauss_elim() {
    for (int i = 0; i < sz(equa); ++i) {
        int p = -1;
        for (int j = 0; j < n; ++j)
            if (equa[i][j]) { p = j; break; }
        if (p < 0) {
            if (equa[i][n]) return false;
            continue;
        }
        for (int j = 0; j < sz(equa); ++j)
            if (i != j && equa[j][p])
                equa[j] ^= equa[i];
    }
    return true;
}

int solve() {
    int ans = 0;
    for (int l = LG_MAX; l >= 0; --l) {
        a[n] = (ans + (1 << l)) ^ k;
        build(l);
        bool chk = gauss_elim();
        ans += chk << l;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    // freopen("inp.txt", "r", stdin);
    cin >> test;
    while (test--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << solve() << "\n";
    }
    return 0;
}