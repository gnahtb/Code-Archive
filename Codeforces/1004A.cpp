#include <bits/stdc++.h>

using namespace std;

const int maxN = 105;

int n, d, x[maxN], ans = 2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i < n; ++i)
    {
        if (x[i + 1] - x[i] < d + d) continue;
        int u = x[i] + d, v = x[i + 1] - d;
        ans += u == v ? 1 : 2;
    }
    cout << ans << "\n";
    return 0;
}
