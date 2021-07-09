#include <bits/stdc++.h>

using namespace std;

int n, w[100005], h[100005];
string ans = "YES";

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> w[i] >> h[i];
    if (h[1] < w[1]) swap(h[1], w[1]);
    for (int i = 2; i <= n; ++i)
    {
        if (h[i] > w[i]) swap(h[i], w[i]);
        if (h[i] > h[i - 1]) { ans = "NO"; break; }
        if (w[i] <= h[i - 1]) swap(w[i], h[i]);
    }
    cout << ans << "\n";
    return 0;
}
