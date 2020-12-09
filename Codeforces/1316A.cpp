#include <bits/stdc++.h>

using namespace std;

const int N = 1002;

int test, n, m, a[N];

int main() {
    cin >> test;
    while (test--) {
        cin >> n >> m;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        int ans = min(sum, m);
        cout << ans << "\n";
    }
    return 0;
}
