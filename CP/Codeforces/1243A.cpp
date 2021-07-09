#include <bits/stdc++.h>

using namespace std;

const int N = 1002;

int k;
int n, a[N];

int main() {
    cin >> k;
    while (k--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, min(i, a[i]));
        }
        cout << ans << "\n";
    }
    return 0;
}
