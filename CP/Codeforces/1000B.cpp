#include <bits/stdc++.h>

using namespace std;

#define odd(a) ((a) & 1)

const int maxN = 1E5 + 5;

int n, m, a[maxN], p[maxN], q[maxN], ans = 0;

template <class T>
void maximize(T &a, T b) { if (a < b) a = b; }

void prep()
{
    p[0] = q[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1] + (odd(i) ? a[i] - a[i - 1] : 0);
        q[i] = q[i - 1] + (odd(i) ? 0 : a[i] - a[i - 1]);
    }
}

void solve()
{
    ans = p[n];
    for (int i = 0; i < n; ++i)
    {
        if (!odd(i) || a[i + 1] - a[i] < 2) continue;
        int cur = p[i] + a[i + 1] - a[i] - 1 + q[n] - q[i + 1];
        maximize(ans, cur);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[0] = 0; a[++n] = m;
    prep();
    solve();
    cout << ans << "\n";
    return 0;
}
