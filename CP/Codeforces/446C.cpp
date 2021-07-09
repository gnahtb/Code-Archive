#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define sqr(a) ((a) * (a))
#define odd(a) ((a) & 1)

typedef long long ll;

struct TMat {
    ll a[3][3];
    TMat() { memset(a, 0, sizeof a); }
    ll* operator [](int i) { return a[i]; }
};
struct TNode {
    int il = 0, ir = 0;
    ll sum = 0;
    TMat base;
};

const int lim = 3e5 + 5;
const ll mod = 1e9 + 9;

int n, m;
ll fib[lim], sfib[lim], a[lim];
TMat origin[lim];
TNode st[lim << 2];

TMat operator *(TMat x, TMat y) {
    TMat z;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                (z[i][j] += x[i][k] * y[k][j] % mod) %= mod;
    return z;
}

TMat operator ^(TMat x, ll y) {
    TMat z = x;
    for (--y; y; y >>= 1, x = sqr(x))
        if (odd(y)) z = z * x;
    return z;
}

void prep() {
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= n; ++i)
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    for (int i = 1; i <= n; ++i)
        sfib[i] = (sfib[i - 1] + fib[i]) % mod;
    for (int i = 2; i <= n; ++i)
        origin[i] = origin[i - 1] * origin[1];
}

ll func(TMat &mat, int param) {
    if (param == 0) return 0;
    if (param == 1) return mat[0][0];
    if (param == 2) return mat[0][2];
    TMat tmp = mat * origin[param - 2];
    return tmp[0][2];
}

#define mid ((l + r) >> 1)
#define next (i << 1)
void build(int i, int l, int r) {
    st[i].il = l; st[i].ir = r;
    if (l == r) return;
    build(next, l, mid);
    build(next + 1, mid + 1, r);
}

void update(int i, int l, int r) {
    if (st[i].il > r || st[i].ir < l) return;
    (st[i].sum += sfib[min(st[i].ir, r) - l + 1] - sfib[max(st[i].il, l) - l] + mod) %= mod;
    if (l <= st[i].il && st[i].ir <= r) {
        for (int t = 0; t < 3; ++t)
            (st[i].base[0][t] += fib[st[i].il - l + t + 1]) %= mod;
        return;
    }
    update(next, l, r);
    update(next + 1, l, r);
}

ll query(int i, int l, int r) {
    if (st[i].il > r || st[i].ir < l) return 0;
    if (l <= st[i].il && st[i].ir <= r) return st[i].sum;
    int tl = max(l, st[i].il), tr = min(r, st[i].ir);
    ll tmp = func(st[i].base, tr - st[i].il + 1), tmp1 = func(st[i].base, tl - st[i].il);
    tmp = (tmp - tmp1 + mod) % mod;
    return (query(next, l, r) + query(next + 1, l, r) + tmp) % mod;
}
#undef mid
#undef next

void init() {
    origin[1][1][0] = 1;
    origin[1][0][1] = origin[1][1][1] = 1;
    origin[1][0][2] = origin[1][1][2] = origin[1][2][2] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]), (a[i] += a[i - 1]) %= mod;
    init();
    prep();
    build(1, 1, n);
    while (m--) {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1) update(1, l, r);
        else {
            ll ans = (query(1, l, r) + a[r] - a[l - 1] + mod) % mod;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
