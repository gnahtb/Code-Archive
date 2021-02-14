#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        long long n, k;
        cin >> n >> k;
        if (n > k) {
            long long exp_sum = (n / k + (n % k > 0)) * k;
            long long ans = exp_sum / n;
            if (exp_sum % n > 0) ++ans;
            cout << ans << "\n";
        } else {
            long long ans = k / n;
            if (k % n > 0) ++ans;
            cout << ans << "\n";
        }
    }
    return 0;
}