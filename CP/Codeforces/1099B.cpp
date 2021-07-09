#include <bits/stdc++.h>

using namespace std;

int n, ans = INT_MAX;

int main() {
    cin >> n;
    for (int i = 1; i * i <= n; ++i) {
        int tmp = i + n / i + (n % i > 0);
        ans = min(ans, tmp);
    }
    cout << ans << "\n";
    return 0;
}
