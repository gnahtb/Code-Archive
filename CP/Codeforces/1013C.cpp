#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1E5 + 5;

int n, a[N * 2];
ll ans = LLONG_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n + n; ++i) cin >> a[i];
    sort(a + 1, a + n + n + 1);
    ans = ll(a[n] - a[1]) * ll(a[n + n] - a[n + 1]);
    for (int i = 2; i <= n; ++i) {
        int x = a[n + i - 1] - a[i];
        ans = min(ans, ll(x) * ll(a[n + n] - a[1]));
    }
    cout << ans << "\n";
    return 0;
}
