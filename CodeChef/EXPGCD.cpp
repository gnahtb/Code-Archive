#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;
using ll = long long;

ll power(ll x, ll y, ll z) {
    if (y == 0) return 1 % z;
    ll t = power(x, y >> 1, z);
    (t *= t) %= z;
    if ((y & 1) == 1) (t *= x) %= z;
    return t;
}

const int N = 2e5;
const int Q = 2e5 + 2;
const ll MOD = 1e9 + 7;

int q, k, n[Q], cnt[N + 2];
ll fa[N + 2], fai[N + 2], old[N + 2], con[N + 2], ans[N + 2];
vector<int> dv[N + 2];

void prep() {
    fa[0] = 1;
    for (int i = 1; i <= N; ++i) fa[i] = fa[i - 1] * i % MOD;
    fai[N] = power(fa[N], MOD - 2, MOD);
    for (int i = N; i; --i) fai[i - 1] = fai[i] * i % MOD;
}

ll nCr(ll n, ll r) {
    if (n < r) return 0;
    return fa[n] * fai[r] % MOD * fai[n - r] % MOD;
}

ll nPr(ll n, ll r) {
    if (n < r) return 0;
    return fa[n] * fai[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    // freopen("inp.txt", "r", stdin);
    cin >> q >> k;
    // fill(cnt + 1, cnt + N + 1, 1);
    prep();
    for (int i = 1; i <= N; ++i)
        for (int j = i; j <= N; j += i) {
            ++cnt[i];
            dv[j].push_back(i);
        }
    for (int i = 1; i <= N; ++i)
        sort(dv[i].begin(), dv[i].end(), greater<int>());
    for (int i = N; i; --i) {
        con[i] = nPr(cnt[i], k);
        for (int j = i * 2; j <= N; j += i) (con[i] += MOD - con[j]) %= MOD;
        (ans[N] += i * con[i] % MOD) %= MOD;
    }
    copy(con + 1, con + N, old + 1);
    for (int i = N; i > 1; --i) {
        ans[i - 1] = ans[i];
        for (int j = 0; j < sz(dv[i]); ++j) {
            (con[dv[i][j]] += MOD - nPr(cnt[dv[i][j]], k)) %= MOD;
            --cnt[dv[i][j]];
            (con[dv[i][j]] += nPr(cnt[dv[i][j]], k)) %= MOD;
            (ans[i - 1] += (MOD - old[dv[i][j]] + con[dv[i][j]]) % MOD * dv[i][j] % MOD) %= MOD;
            for (int k = j + 1; k < sz(dv[i]); ++k) {
                if (dv[i][j] % dv[i][k] == 0) {
                    (con[dv[i][k]] += (old[dv[i][j]] + MOD - con[dv[i][j]]) % MOD) %= MOD;
                }
            }
            old[dv[i][j]] = con[dv[i][j]];
            // --cnt[dv[i][j]];
            // con[dv[i][j]] = nPr(cnt[dv[i][j]], k);
            // for (int k = 0; k < j; ++k)
            //     if (dv[i][k] % dv[i][j] == 0) {
            //         (con[dv[i][j]] += MOD - con[dv[i][k]]) %= MOD;
            //     }
            // (ans[i - 1] += con[dv[i][j]] * dv[i][j] % MOD) %= MOD;
        }
    }
    while (q--) {
        int n;
        cin >> n;
        ll tmp = power(nPr(n, k), MOD - 2, MOD) * ans[n] % MOD;
        cout << tmp << "\n";
    }
    return 0;
}