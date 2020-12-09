#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll ans = 0;

int main() {
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int t = n / i;
        ans += ((ll)(1 + t) * t / 2LL - 1LL) * 4LL;
    }
    cout << ans << "\n";
    return 0;
}
