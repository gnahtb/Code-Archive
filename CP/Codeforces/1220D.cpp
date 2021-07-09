#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 2;

int n, ans = INT_MAX, pw2[N], cnt[100];
ll b[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        ll bt = b[i];
        while (bt % 2 == 0) {
            ++pw2[i];
            bt /= 2;
        }
        ++cnt[pw2[i]];
    }
    int cur = 0;
    for (int i = 0; i < 100; ++i)
        if (ans > n - cnt[i]) {
            cur = i;
            ans = n - cnt[i];
        }
    cout << ans << "\n";
    for (int i = 0; i < n; ++i)
        if (pw2[i] != cur) cout << b[i] << " ";
    return 0;
}
