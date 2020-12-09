#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

typedef long long ll;

const int LIM = 8;
const int Max = 100;

ll w, cnt[LIM + 3], cur[LIM + 3];

int check(ll* c, bool (&f)[Max][Max]) {
    vector<int> a;
    for (int i = 1; i <= LIM; ++i)
        for (ll j = 1; j <= min(8LL, c[i]); ++j)
            a.push_back(i);
    memset(f, 0, sizeof f);
    f[0][0] = true;
    for (int i = 0; i < sz(a); ++i) {
        for (int j = 0; j < Max; ++j) {
            f[i + 1][j] |= f[i][j];
            if (j + a[i] < Max)
                f[i + 1][j + a[i]] |= f[i][j];
        }
    }
    return sz(a);
}

bool chk[Max][Max], chk1[Max][Max];
ll solve() {
    ll sum = 0;
    for (ll i = LIM; i; --i) {
        cur[i] = min((w - sum) / i, cnt[i]);
        cnt[i] -= cur[i];
        sum += cur[i] * i;
    }
    int tmp = check(cnt, chk);
    int tmp1 = check(cur, chk1);
    ll ret = sum;
    for (int d = 1; d <= min(int(w - sum), 8); ++d)
        for (int a = 0; a + d < Max; ++a)
            if (chk[tmp][a + d] && chk1[tmp1][a])
                ret = max(ret, sum + d);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> w;
    for (int i = 1; i <= LIM; ++i) cin >> cnt[i];
    cout << solve() << "\n";
    return 0;
}
