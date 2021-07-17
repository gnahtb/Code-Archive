#include <bits/stdc++.h>

using namespace std;

const int M = 1e5 + 2;

int n, m;
pair<int, int> a[M];
long long ans;

int main() {
    cin >> n >> m;
    int d = n;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].second >> a[i].first;
        d = __gcd(d, a[i].second);
    }
    if (d > 1) {
        cout << "-1";
        return 0;
    }
    sort(a + 1, a + m + 1);
    d = n;
    for (int i = 1; i <= m; ++i) {
        int d1 = __gcd(d, a[i].second);
        ans += 1LL * (d - d1) * a[i].first;
        d = d1;
    }
    cout << ans;
    return 0;
}