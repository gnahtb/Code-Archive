#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 1E5 + 5;
const ll INF = 3E18;

int n, x[N_MAX];
ll a[N_MAX], b[N_MAX], k[N_MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 2; i <= n; ++i) cin >> x[i] >> k[i];
    for (int i = n; i > 1; --i) {
        ll c = b[i] - a[i];
        if (c < 0) c = (-INF / c) < k[i] ? -INF : c *= k[i];
        b[x[i]] = max(-INF, min(INF, b[x[i]] + c));
    }
    cout << (b[1] >= 0 ? "YES\n" : "NO\n");
    return 0;
}
