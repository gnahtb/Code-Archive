#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int limit = 500005;

int q, n = 0, a[limit], i = 1;
ll cur = 0;
double ans = 0;

template <typename T>
void maximize(T &a, T b) { if (a < b) a = b; }

int main()
{
    ios_base::sync_with_stdio(false);
    (cout << fixed).precision(10);
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 2) { cout << ans << "\n"; continue; }
        cin >> t;
        a[++n] = t;
        while (i < n && ll(a[n]) + cur > ll(a[i]) * ll(i))
            cur += ll(a[i++]);
        maximize(ans, a[n] - double(ll(a[n]) + cur)/i);
    }
    return 0;
}
