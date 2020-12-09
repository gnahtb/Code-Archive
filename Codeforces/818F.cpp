#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll q, n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q;
    while (q--)
    {
        cin >> n;
        ll L = 0, R = (n * (n - 1)) >> 1LL, ans = -1;
        while (L <= R)
        {
            m = (L + R) >> 1LL;
            ll b = (m + 1) >> 1LL, u = n - b;
            if (u < 0) { R = m - 1; continue; }
            if (((u * (u - 1)) >> 1LL) + b >= m) ans = m, L = m + 1;
            else R = m - 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
