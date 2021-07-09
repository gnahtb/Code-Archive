#include <bits/stdc++.h>

using namespace std;

const int LIM = 1000;

int n, k, cnt[LIM + 2], ans;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        ++cnt[t];
    }
    n = n / 2 + n % 2;
    int tmp = 0;
    for (int i = 1; i <= LIM; ++i) {
        ans += cnt[i] / 2 * 2;
        n -= cnt[i] / 2;
        tmp += cnt[i] % 2;
    }
    ans += n;
    cout << ans << endl;
    return 0;
}
