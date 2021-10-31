#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int test;
ll n, k;

int main() {
    cin >> test;
    while (test--) {
        cin >> n >> k;
        ll cur = 1, ans = 0;
        while (cur < n && cur <= k) {
            cur *= 2;
            ++ans;
        }
        if (cur < n) {
            ll need = n - cur;
            ans += (need + k - 1) / k;
        }
        cout << ans << endl;
    }
    return 0;
}