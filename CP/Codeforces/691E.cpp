#include <algorithm>
#include <iostream>

using namespace std;

#define sqr(a) (a) * (a)
#define odd(a) ((a) & 1)

typedef long long ll;

const int N = 100;
const ll mod = 1000000007;

struct TMat {
    ll a[N][N];
    TMat() { fill(a[0], a[N], 0); };
    ll* operator [](int i) { return a[i]; }
};

TMat operator *(TMat &a, TMat &b) {
    TMat c;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                (c[i][j] += a[i][k] * b[k][j] % mod) %= mod;
    return c;
}

TMat operator ^(TMat a, ll b) {
    TMat c = a;
    for (--b; b; b >>= 1, a = sqr(a)) if (odd(b)) c = c * a;
    return c;
}

int n;
ll k, a[N], ans = 0;
TMat origin, base;

void solve() {
    fill(origin[0], origin[0] + n, 1);
    for (int j = 0; j < n; ++j)
        for (int i = 0; i < n; ++i)
            base[i][j] = !(__builtin_popcountll(a[i] ^ a[j]) % 3);
    base = base ^ (k - 1);
    origin = origin * base;
    for (int i = 0; i < n; ++i) (ans += origin[0][i]) %= mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    if (k == 1) { cout << n << "\n"; return 0; }
    for (int i = 0; i < n; ++i) cin >> a[i];
    solve();
    cout << ans << "\n";
    return 0;
}
