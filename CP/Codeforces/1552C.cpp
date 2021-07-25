#include <bits/stdc++.h>

using namespace std;

const int N = 102;

int test, n, k, sum[N * 2], x[N * 2], y[N * 2];

bool inter(int x1, int y1, int x2, int y2) {
    if (x1 < x2 && y1 > x2 && y1 < y2) return true;
    if (x2 < x1 && y2 > x1 && y2 < y1) return true;
    return false;
}

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> test;
    while (test--) {
        memset(sum, 0, sizeof(sum));
        cin >> n >> k;
        int tmp = (n * 2 - k * 2) / 2;
        int ans = tmp * (tmp - 1) / 2;
        for (int i = 1; i <= k; ++i) {
            cin >> x[i] >> y[i];
            if (x[i] > y[i]) swap(x[i], y[i]);
            ++sum[x[i]];
            ++sum[y[i]];
        }
        for (int i = 1; i <= n * 2; ++i) sum[i] += sum[i - 1];
        for (int i = 1; i <= k; ++i) {
            for (int j = i + 1; j <= k; ++j) {
                if (inter(x[i], y[i], x[j], y[j])) {
                    ++ans;
                    // cerr << i << " " << j << endl;
                }
            }
        }
        for (int i = 1; i <= k; ++i) {
            int t = y[i] - x[i] - 1 - (sum[y[i] - 1] - sum[x[i]]);
            int t1 = n * 2 - k * 2 - t;
            ans += min(t, t1);
        }
        cout << ans << endl;
    }
    return 0;
}