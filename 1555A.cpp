#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int test;
ll n;

int main() {
    cin >> test;
    while (test--) {
        cin >> n;
        ll ans = LLONG_MAX;
        ll a = n / 10;
        ans = min(ans, (n + 9) / 10 * 25);
        ll b = (n % 10) / 8;
        ans = min(ans, a * 25 + ((n % 10) + 7) / 8 * 20);
        ll c = (((n % 10) % 8) + 5) / 6;
        ans = min(ans, a * 25 + b * 20 + c * 15);
        ans = min(ans, (n + 5) / 6 * 15);
        ans = min(ans, (n + 7) / 8 * 20);
        ans = min(ans, (n / 8) * 20 + (n % 8 + 5) / 6 * 15);
        ans = min(ans, (n / 10) * 25 + (n % 10 + 5) / 6 * 15);
        cout << ans << endl;
    }
    return 0;
}