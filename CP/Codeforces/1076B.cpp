#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, ans = 0;

int main() {
    cin >> n;
    if (n % 2 != 0) {
        ll prime = n;
        for (ll i = 2; i * i <= n; ++i)
            if (n % i == 0) { prime = i; break; }
        ++ans;
        n -= prime;
    }
    ans += n / 2;
    cout << ans << "\n";
    return 0;
}
