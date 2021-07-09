#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;

int n, k, a[N], sum[N];

bool check(int x) {
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1];
        if (a[i] >= x) ++sum[i];
        else --sum[i];
    }
    int current_min = 0;
    for (int i = k; i <= n; ++i) {
        current_min = min(current_min, sum[i - k]);
        if (sum[i] > current_min) {
            return true;
        }
    }
    return false;
}

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (check(m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans;
    return 0;
}