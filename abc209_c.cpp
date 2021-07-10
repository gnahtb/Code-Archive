#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;
const long long MOD = 1e9 + 7;

int n, c[N];
long long ans = 1;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; ++i) {
        (ans *= c[i] - i + 1) %= MOD;
    }
    cout << ans;
    return 0;
}