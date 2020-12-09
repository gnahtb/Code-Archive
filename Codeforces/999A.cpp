#include <bits/stdc++.h>

using namespace std;

int n, k, a[105], l, r, ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[n + 1] = INT_MAX;
    for (l = 1; l <= n; ++l) if (a[l] <= k) ++ans; else break;
    for (r = n; r > l; --r) if (a[r] <= k) ++ans; else break;
    cout << ans << "\n";
    return 0;
}
