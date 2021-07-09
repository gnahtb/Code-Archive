#include <bits/stdc++.h>

using namespace std;

int n, k, x = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int mod = 1; mod < k; ++mod) {
        if (n % mod != 0) continue;
        x = min(x, (n / mod) * k + mod);
    }
    cout << x << "\n";
    return 0;
}
