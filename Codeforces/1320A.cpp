#include <bits/stdc++.h>

using namespace std;

const int N = 5e5;

int n;
long long sum[N * 2 + 2];

int main() {
    memset(sum, 0, sizeof(sum));
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int b;
        cin >> b;
        sum[b - i + N] += b;
    }
    long long ans = 0;
    for (int i = 0; i < N * 2 + 2; ++i)
        ans = max(ans, sum[i]);
    cout << ans << "\n";
    return 0;
}
