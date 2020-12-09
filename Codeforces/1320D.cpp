#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;
using ll = long long;

ll Power(ll x, ll y, ll z) {
    if (y == 0) return 1 % z;
    ll t = Power(x, y / 2, z);
    (t *= t) %= z;
    if (y % 2 != 0) (t *= x) %= z;
    return t;
}

const int N = 2e5 + 2;
const int BASE = 37, MOD = 1504464461;

int n, q, sum[N];
string t;
vector<int> zeroes, par;
vector<ll> hashval, pw;

ll GetHash(int l, int r) {
    if (l > r) return -1;
    ll tmp = (hashval[r] - hashval[l - 1] * pw[r - l + 1] % MOD + MOD) % MOD;
    return tmp;
}

int FindUp(int x) {
    int l = 0, r = sz(zeroes) - 1, res = -1;
    while (l <= r) {
        int md = (l + r) / 2;
        if (zeroes[md] >= x) {
            res = md;
            r = md - 1;
        } else {
            l = md + 1;
        }
    }
    return res;
}

int FindLow(int x) {
    int l = 0, r = sz(zeroes) - 1, res = -1;
    while (l <= r) {
        int md = (l + r) / 2;
        if (zeroes[md] <= x) {
            res = md;
            l = md + 1;
        } else {
            r = md - 1;
        }
    }
    return res;
}

string Solve(int l1, int l2, int len) {
    int r1 = l1 + len - 1, r2 = l2 + len - 1;
    if (sum[r1] - sum[l1 - 1] != sum[r2] - sum[l2 - 1]) return "NO";
    if (sum[r1] > sum[l1 - 1]) {
        int l11 = FindUp(l1), r11 = FindLow(r1);
        int l21 = FindUp(l2), r21 = FindLow(r2);
        if (abs(zeroes[l11] - l1) % 2 != abs(zeroes[l21] - l2) % 2) return "NO";
        if (abs(zeroes[r11] - r1) % 2 != abs(zeroes[r21] - r2) % 2) return "NO";
        ll h1 = GetHash(l11 + 1, r11), h2 = GetHash(l21 + 1, r21);
        if (h1 == h2) return "YES";
        else return "NO";
    } else return "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> t >> q;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + (t[i - 1] == '0');
        if (t[i - 1] == '0') {
            zeroes.push_back(i);
        }
    }
    par.resize(sz(zeroes), -1);
    hashval.resize(sz(zeroes) + 2, 0);
    pw.resize(sz(zeroes) + 2, 1);
    for (int i = 1; i < sz(par); ++i) {
        par[i - 1] = (zeroes[i] - zeroes[i - 1] - 1) % 2;
        pw[i] = pw[i - 1] * BASE % MOD;
        hashval[i] = (hashval[i - 1] * BASE + par[i - 1] + 1) % MOD;
    }
    while (q--) {
        int l1, l2, len;
        cin >> l1 >> l2 >> len;
        cout << Solve(l1, l2, len) << "\n";
    }
    return 0;
}
