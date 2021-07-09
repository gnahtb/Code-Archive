#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;
using ll = long long;

const int N = 1e6 + 2;
const ll oo = 1e18;

int n;
ll x, y, a[N], f[N][3], g[N], ans;
vector<ll> primes;

void Opt(ll& lhs, ll rhs) {
    if (lhs > rhs) lhs = rhs;
}

void PrimeFact(ll x, vector<ll>& v) {
    v.clear();
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0) {
            while (x % i == 0) x /= i;
            v.push_back(i);
        }
    if (x > 1) v.push_back(x);
}

bool Check(ll a, ll b) {
    if (a % b == 1 || a % b == b - 1 || a % b == 0) return true;
    return false;
}

ll w(ll a, ll b) {
    if (a % b == 0) return 0;
    return y;
}

void Solve1(bool flag = false) {
    PrimeFact(a[n], primes);
    for (int j = 0; j < sz(primes); ++j) {
        fill(g, g + N, oo);
        g[n] = flag * y;
        for (int i = n - 1; i; --i) {
            if (Check(a[i], primes[j])) {
                Opt(g[i], g[i + 1] + w(a[i], primes[j]));
            }
            Opt(ans, x * (i - 1) + g[i]);
        }
    }
}

// 0 -> has not opened segment
// 1 -> currently in segment
// 2 -> got out of segment
void Solve2(bool flag = false) {
    PrimeFact(a[1], primes);
    for (int j = 0; j < sz(primes); ++j) {
        fill(f[0], f[N], oo);
        f[1][0] = flag * y;
        for (int i = 2; i <= n; ++i) {
            // remain
            if (Check(a[i], primes[j])) {
                Opt(f[i][0], f[i - 1][0] + w(a[i], primes[j]));
                Opt(f[i][2], f[i - 1][2] + w(a[i], primes[j]));
            }
            Opt(f[i][1], f[i - 1][1] + x);
            
            // open segment
            Opt(f[i][1], f[i - 1][0] + x);

            // close segment
            if (Check(a[i], primes[j]))
                Opt(f[i][2], f[i - 1][1] + w(a[i], primes[j]));
        }
        Opt(ans, f[n][0]);
        Opt(ans, f[n][1]);
        Opt(ans, f[n][2]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ans = x * (n - 1);
    Solve1();
    ++a[n];
    Solve1(true);
    --a[n];
    if (a[n] > 2) {
        --a[n];
        Solve1(true);
        ++a[n];
    }
    Solve2();
    ++a[1];
    Solve2(true);
    --a[1];
    if (a[1] > 2) {
        --a[1];
        Solve2(true);
        ++a[1];
    }
    cout << ans << "\n";
    return 0;
}
