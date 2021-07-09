#include <bits/stdc++.h>

using namespace std;

const int N = 1002;

int n, t[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }
    sort(t + 1, t + n + 1);
    int ans = INT_MAX;
    for (int i = 0; i <= n / 2; ++i) {
        int sum = 0;
        for (int k = 1; k <= i; ++k) {
            sum += min(abs(t[n - k + 1] - t[k]), 24 - abs(t[n - k + 1] - t[k]));
        }
        int j = i + 1;
        for (int k = i + 1; k <= n / 2; ++k, j += 2)
            sum += min(abs(t[j + 1] - t[j]), 24 - abs(t[j + 1] - t[j]));
        ans = min(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}