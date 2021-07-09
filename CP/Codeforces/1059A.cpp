#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1E5 + 5;

int n, L, a, t[N], l[N];
ll ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> L >> a;
    for (int i = 1; i <= n; ++i) cin >> t[i] >> l[i];
    ans = t[1] / a;
    for (int i = 1; i < n; ++i)
        ans += (ll)(t[i + 1] - t[i] - l[i]) / a;
    ans += (ll)(L - t[n] - l[n]) / a;
    cout << ans << "\n";
    return 0;
}
