#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;
using ll = long long;

ll c[35][35], f[32];

ll Trau(int r1, int r2) {
    int ret = 0;
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < r2; ++j)
            if ((i & j) == 0) {
                cout << i << " " << j << "\n";
                ++ret;
            }
    return ret;
}

void Prep() {
    for (int i = 0; i < 35; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    f[0] = 1;
    for (int i = 1; i < 32; ++i) {
        for (int j = 0; j <= i; ++j)
            f[i] += c[i][j] * (1LL << (i - j));
    }
}

bool GetBit(int b, int i) {
    return b >> i & 1;
}

ll Solve(ll r1, ll r2) {
    ll ret = 0;
    vector<int> v1, v2;
    v1.clear();
    v2.clear();
    for (int i = 0; i < 30; ++i) {
        if (GetBit(r1, i)) v1.push_back(i);
        if (GetBit(r2, i)) v2.push_back(i);
    }
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    ll t1 = 0, t2 = 0;
    // int len = max(v1.front(), v2.front()) + 1;
    for (int i = 0; i < sz(v1); ++i) {
        t2 = 0;
        for (int j = 0; j < sz(v2); ++j) {
            if ((t1 & t2) != 0) break;
            int re1 = v1[i];
            int re2 = v2[j];
            int tmp = abs(re1 - re2);
            if (re1 > re2) {
                for (int jj = 0; jj < j; ++jj)
                    if (v2[jj] < re1) --tmp;
            } else if (re1 < re2) {
                for (int ii = 0; ii < i; ++ii)
                    if (v1[ii] < re2) --tmp;
            }
            ll delta = f[min(re1, re2)] * (1LL << tmp);
            ret += delta;
            t2 += 1LL << v2[j];
        }
        t1 += 1LL << v1[i];
    }
    return ret;
}

int t;
int l, r;

int main() {
    Prep();
    // cout << Solve(1, 5) << "\n";
    // cout << Trau(1, 5) << "\n";
    cin >> t;
    while (t--) {
        cin >> l >> r;
        ll t1 = Solve(r + 1, r + 1);
        ll t2 = l > 0 ? Solve(l, r + 1) : 0;
        ll t3 = l > 0 ? Solve(l, l) : 0;
        ll ans = t1 + t3 - t2 * 2;
        cout << ans << "\n";
    }
    return 0;
}
