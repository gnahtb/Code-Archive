#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int t, n;
long long A, B;
pair<long long, long long> a[N];

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> A >> B >> n;
        string ans = "YES";
        for (int i = 1; i <= n; ++i) cin >> a[i].first;
        for (int i = 1; i <= n; ++i) cin >> a[i].second;
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            long long tmp = a[i].second / A + (a[i].second % A > 0);
            if (B <= tmp * a[i].first && B < (tmp - 1) * a[i].first) {
                ans = "NO";
                break;
            }
            B -= tmp * a[i].first;
            if (B <= 0 && i < n) {
                ans = "NO";
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}