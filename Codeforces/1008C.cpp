#include <bits/stdc++.h>

using namespace std;

int n, a[100005], b[100005], ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], b[i] = i;
    sort(b + 1, b + n + 1, [](int x, int y) { return a[x] > a[y]; });
    // for (int i = 1; i <= n; ++i) cout << b[i] << " ";
    // cout << "\n\n";
    for (int i = 1, j = 1; i <= n && j <= n; ++i, ++j)
    {
        while (j <= n && a[b[i]] == a[b[j]]) ++j;
        // cout << i << " " << j << "\n";
        if (j <= n && a[b[i]] > a[b[j]]) ++ans;
    }
    cout << ans << "\n";
    return 0;
}
