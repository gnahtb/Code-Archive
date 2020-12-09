#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a[105], ans = 0;
    ios_base::sync_with_stdio(false);
    cin >> n;
    memset(a, 0, sizeof a);
    a[n + 1] = 10000;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1, j; i <= n; i += j) {
        int p = -1;
        for (j = 0; ; ++j)
            if (a[i + j] - a[i] == j) p = j - 1;
            else break;
        if (a[i] == 1) ++p;
        if (a[i + j - 1] == 1000) ++p;
        ans = max(ans, p);
    }
    cout << ans << "\n";
    return 0;
}
