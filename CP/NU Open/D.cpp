#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 2;

int n, k, a[N], d[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long ans = LLONG_MAX;
    for (int i = 1; i + k - 1 <= n; ++i) {
        long long cost = a[i + k - 1] - a[i];
        
        // start from left
        long long cost1 = cost + abs(a[i]);
        // start from right
        long long cost2 = cost + abs(a[i + k - 1]);

        // cout << cost1 << " " << endl;

        ans = min(ans, min(cost1, cost2));
    }
    cout << ans;
    return 0;
}