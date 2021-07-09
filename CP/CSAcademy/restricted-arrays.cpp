#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define sz(a) int(a.size())

typedef long long ll;

const int maxN = 1E5 + 5;
const ll mod = 1E9 + 7;

int n, k, x = 0, a[maxN], u[maxN], c[maxN];
ll f[maxN];

void prep() {
    set<int> s;
    fill(c, c + maxN, 0);
    for (int i = 1; i <= n; ++i) {
        if (i > k) {
            --c[a[i - k]];
            if (!c[a[i - k]]) s.erase(s.find(a[i - k]));
        }
        ++c[a[i]];
        s.insert(a[i]);
        u[i] = sz(s);
        x = max(x, u[i]);
    }
}

void solve() {
    fill(c, c + maxN, 0);
    fill(f, f + maxN, 0);
    f[1] = x; ++c[a[1]];
    for (int i = 2; i <= n; ++i) {
        ++c[a[i]];
        if (i > k) --c[a[i - k]];
        ll d = c[a[i]] > 1 ? 1 : x - u[i] + 1;
        f[i] = d * f[i - 1] % mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    prep();
    solve();
    printf("%lld\n", f[n]);
}