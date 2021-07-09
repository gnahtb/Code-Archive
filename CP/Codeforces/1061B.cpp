#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 1e5 + 5;

int n, m, a[N_MAX];
ll sum = 0, ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1, j = a[1]; i <= n; ++i) {
        ++ans; --j;
        if (j > a[i + 1]) {
            ans += j - a[i + 1];
            j = a[i + 1];
        }
    }
    cout << sum - ans << "\n";
    return 0;
}
