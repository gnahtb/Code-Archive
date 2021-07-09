#include <bits/stdc++.h>

using namespace std;

int n, p, k;
long long ans;
map<int, int> m;

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> p >> k;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        int a4 = 1LL * a * a % p * a % p * a % p;
        int t = (1LL * a4 - 1LL * a * k % p + p) % p;
        if (m.find(t) != m.end()) ans += m[t];
        ++m[t];
    }

    cout << ans << "\n";

    return 0;
}
