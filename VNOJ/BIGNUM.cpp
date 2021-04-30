#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define sz(a) (int)a.size()

struct Bigint {
    const static ll BASE = 1e7;
    const static int BASE_LEN = 7;

    vector<ll> a;

    size_t size() { return a.size(); }
    ll& operator [](int i) { return a[i]; }
    void resize(size_t t) { a.resize(t); }
    void push(ll x) { a.push_back(x); }

    void fix(bool rsz = true) {
        a.push_back(0);
        for (int i = 0; i < sz(a) - 1; ++i) {
            if (a[i] >= 0) {
                a[i + 1] += a[i] / BASE;
                a[i] %= BASE;
            } else {
                --a[i + 1];
                a[i] += BASE;
            }
        }
        if (!rsz) return;
        while (a.back() == 0 && sz(a) > 1) a.pop_back();
    }
} a, b;

bool operator <(Bigint& lhs, Bigint& rhs) {
    if (sz(lhs) != sz(rhs)) return sz(lhs) < sz(rhs);
    for (int i = sz(lhs) - 1; i >= 0; --i)
        if (lhs[i] != rhs[i]) return lhs[i] < rhs[i];
    return false;
}

istream& operator >>(istream& i, Bigint& x) {
    string s;
    i >> s;
    reverse(s.begin(), s.end());
    ll cur = 0, pw = 1;
    int cnt = 0;
    for (int it = 0; it < sz(s); ++it) {
        cur += pw * (s[it] - '0');
        pw *= 10;
        ++cnt;
        if (cnt < x.BASE_LEN && it < sz(s) - 1)
            continue;
        x.push(cur);
        cur = 0;
        cnt = 0;
        pw = 1;
    }
    return i;
}

ostream& operator <<(ostream& o, Bigint &x) {
    for (int i = sz(x) - 1; i >= 0; --i) {
        string s = to_string(x[i]);
        while (i < sz(x) - 1 && sz(s) < x.BASE_LEN)
            s = '0' + s;
        o << s;
    }
    return o;
}

Bigint operator +(Bigint& lhs, Bigint& rhs) {
    Bigint ret;
    int tmp = max(sz(lhs), sz(rhs));
    ret.resize(tmp);
    for (int i = 0; i < tmp; ++i) {
        ll x = i < sz(lhs) ? lhs[i] : 0;
        ll y = i < sz(rhs) ? rhs[i] : 0;
        ret[i] = x + y;
    }
    ret.fix();
    return ret;
}

Bigint operator -(Bigint& lhs, Bigint& rhs) {
    Bigint ret;
    int tmp = max(sz(lhs), sz(rhs));
    ret.resize(tmp);
    for (int i = 0; i < tmp; ++i) {
        ll x = i < sz(lhs) ? lhs[i] : 0;
        ll y = i < sz(rhs) ? rhs[i] : 0;
        ret[i] = x - y;
    }
    ret.fix();
    return ret;
}

Bigint operator *(Bigint &lhs, Bigint &rhs) {
    Bigint ret;
    ret.resize(sz(lhs) + sz(rhs));
    for (int j = 0; j < sz(rhs); ++j) {
        for (int i = 0; i < sz(lhs); ++i)
            ret[i + j] += lhs[i] * rhs[j];
        ret.fix(false);
    }
    ret.fix();
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b;
    bool flag = false;
    if (a < b) swap(a, b), flag = true;
    Bigint ans1 = a + b;
    Bigint ans2 = a - b;
    Bigint ans3 = a * b;
    cout << ans1 << "\n";
    if (flag) cout << "-";
    cout << ans2 << "\n";
    cout << ans3 << "\n";
    return 0;
}