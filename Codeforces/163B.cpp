#include <bits/stdc++.h>
 
using namespace std;
using pii = pair<int, int>;
 
const int N = 1e5 + 2;
const int K = 1e4 + 2;
const double Eps = 1e-9;
 
int n, k, h, idx[N], ans[N], tans[N];
pii a[N];
 
bool Check(double x) {
    for (int i = k, j = n; i; --i) {
        int po = -1;
        while (j > 0) {
            double tmp = x * a[idx[j]].second / h;
            --j;
            if (1.0 * i - tmp <= Eps) {
                po = idx[j + 1];
                break;
            }
        }
        if (po < 0) return false;
        tans[i] = po;
    }
    return true;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k >> h;
    for (int i = 1; i <= n; ++i) cin >> a[i].first;
    for (int i = 1; i <= n; ++i) cin >> a[i].second;
    for (int i = 1; i <= n; ++i) idx[i] = i;
    sort(idx + 1, idx + n + 1, [](int x, int y) { return a[x] < a[y]; });
    double l = 0, r = 1e9;
    int Rep = 100;
    while (Rep--) {
        double md = (l + r) / 2.0;
        if (Check(md)) {
            r = md;
            copy(tans + 1, tans + k + 1, ans + 1);
        } else {
            l = md;
        }
    }
    for (int i = 1; i <= k; ++i) cout << ans[i] << " ";
    return 0;
}
