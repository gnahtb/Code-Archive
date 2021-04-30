#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

typedef long long ll;

const int lim = 1048580;

ll n, m;
int cnt[lim], f[lim];

void sub4() {
    int ans = 0;
    vector<int> u;
    for (int i = 0; i < 31; ++i) if (m >> (ll)i & 1) u.push_back(i);
    memset(cnt, 0, sizeof cnt);
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; ++i) {
        int a, x = 0;
        cin >> a;
        for (int j = 0; j < sz(u); ++j) x += (a >> u[j] & 1) << j;
        ++cnt[x];
    }
    for (int i = 1048575; i >= 0; --i) {
        for (int j = 0; j < 20; ++j)
            if (!(i >> j & 1)) f[i] = max(f[i], f[i ^ 1 << j]);
        f[i] += cnt[i];
    }
    for (int i = 0; i < 1048576; ++i) ans = max(ans, f[i]);
    cout << ans << "\n";
}

void sub3() {
    const int N = 5005;
    int a[N], f[N], ans = 0;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], a[i] &= (int)m;
    sort(a + 1, a + n + 1, greater<int>());
    fill(f, f + N, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j)
            if ((a[i] | a[j]) == a[j]) f[i] = max(f[i], f[j]);
        ans = max(ans, ++f[i]);
    }
    cout << ans << "\n";
}

void sub1() {
    cout << __lg(n) << "\n";
}

void sub2() {
    ll x = __lg(n + 1), y = 0;
    for (ll i = 0; i < 60; ++i)
        if (1LL << i <= n) y += m >> i & 1;
    cout << (1LL << (x - y)) * (y + 1) - 1 << "\n";
}

int main() {
    cin >> n >> m;
    if (n <= 5000) sub3();
    else if (n <= 100000) sub4();
    else if (m == 1152921504606846975) sub1();
    else sub2();
    return 0;
}