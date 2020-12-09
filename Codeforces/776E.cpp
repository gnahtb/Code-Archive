#include <iostream>

using namespace std;

#define odd(a) ((a) & 1)
#define sqr(a) (a) * (a)

typedef long long ll;

const ll mod = 1E9 + 7;

ll n, k;

ll phi(ll x) {
    ll r = x;
    for (ll i = 2; sqr(i) <= x; ++i) if (!(x % i)) {
        while (!(x % i)) x /= i;
        r -= r / i;
    }
    if (x > 1) r -= r / x;
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    if (k > 1000) { cout << "1\n"; return 0; }
    for (int i = 1; i <= k; i += 2) n = phi(n);
    cout << n % mod << "\n";
    return 0;
}
