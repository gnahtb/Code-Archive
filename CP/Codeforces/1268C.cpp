#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 2;

struct FenwickTree {
    int n;
    ll fen[N];

    FenwickTree() {
        memset(fen, 0, sizeof(fen));
    }

    void Init(int nn) { n = nn; }

    void Inc(int i, ll x) {
        for (; i <= n; i += i & -i) fen[i] += x;
    }

    ll Sum(int i) {
        ll ret = 0;
        for (; i; i -= i & -i) ret += fen[i];
        return ret;
    }
} bit1, bit2;

int n;
int a[N], idx[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        idx[a[i]] = i;
    }
    bit1.Init(n);
    bit2.Init(n);
    ll inv = 0;
    for (int i = 1; i <= n; ++i) {
        inv += bit1.Sum(n) - bit1.Sum(idx[i]);
        bit1.Inc(idx[i], 1);
        bit2.Inc(idx[i], idx[i]);
        int l = 1, r = n, med = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (bit1.Sum(m) > (i - 1) / 2) {
                med = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        int cntl = bit1.Sum(med - 1), cntr = bit1.Sum(n) - bit1.Sum(med);
        ll costl = 1LL * med * cntl;
        costl -= bit2.Sum(med - 1);
        costl -= 1LL * cntl * (cntl + 1) / 2;
        ll costr = bit2.Sum(n);
        costr -= bit2.Sum(med);
        costr -= 1LL * med * cntr;
        costr -= 1LL * cntr * (cntr + 1) / 2;
        ll ans = costl + costr + inv;
        cout << ans << " ";
    }
    return 0;
}
