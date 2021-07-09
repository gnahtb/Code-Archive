#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

const int LIM = 100;

struct TMat {
    int a[LIM][LIM];
    TMat() { memset(a, 0, sizeof a); }
    int* operator [](int i) { return a[i]; }
} bs;

int n, t, a[LIM];
vector<int> v;

TMat operator *(TMat& a, TMat& b) {
    TMat c;
    for (int i = 0; i < sz(v); ++i)
        for (int j = i; j < sz(v); ++j)
            for (int k = i; k <= j; ++k)
                c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
    return c;
}

TMat operator ^(TMat a, int b) {
    TMat c = a;
    for (--b; b; b >>= 1, a = a * a)
        if (b & 1) c = c * a;
    return c;
}

inline int p(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}

int fmx[LIM][LIM];
void prep() {
    for (int i = 0; i < n; ++i) {
        fmx[i][i] = 1;
        for (int j = i; j < n; ++j) if (a[i] <= a[j]) {
            for (int k = i; k < j; ++k)
                if (a[i] <= a[k] && a[k] <= a[j])
                    fmx[i][j] = max(fmx[i][j], fmx[i][k] + 1);
            bs[p(a[i])][p(a[j])] = max(bs[p(a[i])][p(a[j])], fmx[i][j]);
        }
    }
    for (int d = 1; d < sz(v); ++d)
        for (int l = 0, r = d; r < sz(v); ++l, ++r)
            bs[l][r] = max(bs[l][r], max(bs[l][r - 1], bs[l + 1][r]));
}

int solve() {
    int ans = 0;
    TMat fn = bs ^ t;
    for (int l = 0; l < sz(v); ++l)
        for (int r = l; r < sz(v); ++r)
            ans = max(ans, fn[l][r]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    for (int i = 0; i < n; ++i)
        cin >> a[i], v.push_back(a[i]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    prep();
    cout << solve() << "\n";
    return 0;
}
