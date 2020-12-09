#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> a, b;
long long ans;

int main() {
    cin >> n >> k;
    a.resize(n + 2);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        ans += a[i + 1] - a[i];
        b.push_back(a[i + 1] - a[i]);
    }
    sort(b.begin(), b.end(), greater<int>());
    for (int i = 0; i < k - 1; ++i) ans -= b[i];
    cout << ans << endl;
    return 0;
}
