#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll inf = 2E18;

int t;
ll n, cnt[61];

ll power(ll x, ll y) {
    if (!y) return 1;
    ll z = power(x, y >> 1);
    if (inf / z <= z) return inf;
    z *= z;
    if (!(y & 1)) return z;
    if (inf / z <= x) return inf;
    return z * x;
}

ll solve() {
    for (int i = 60; i; --cnt[i--]) {
        cnt[i] = (ll)pow((ld)n, (ld)1.0 / i) + 1;
        while (power(cnt[i], i) > n) --cnt[i];
        for (int j = i + i; j <= 60; j += i)
            cnt[i] -= cnt[j];
    }
    return cnt[1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        cout << solve() << "\n";
    }
    return 0;
}
