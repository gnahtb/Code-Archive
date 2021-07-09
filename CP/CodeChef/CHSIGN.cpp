#include <bits/stdc++.h>

using namespace std;

template <typename T> void minimize(T &a, T b) { if (a > b) a = b; }

typedef long long ll;

const int maxN = 1E5 + 5;
const ll inf = 1E18;

int t, n;
ll a[maxN], f[maxN][8];

int getBit(int mask, int id) { return (mask >> id) & 1; }

bool check(int id, int mask)
{
    ll t1 = a[id - 2], t2 = a[id - 1], t3 = a[id];
    if (getBit(mask, 2)) t1 = -t1;
    if (getBit(mask, 1)) t2 = -t2;
    if (getBit(mask, 0)) t3 = -t3;
    return (t1 + t2 > 0 && t2 + t3 > 0 && t1 + t2 + t3 > 0);
}

void solve()
{
    for (int mask = 0; mask < 8; ++mask)
    {
        f[3][mask] = LLONG_MAX;
        if (!check(3, mask)) continue;
        ll t1 = a[1], t2 = a[2], t3 = a[3];
        if (getBit(mask, 2)) t1 = -t1;
        if (getBit(mask, 1)) t2 = -t2;
        if (getBit(mask, 0)) t3 = -t3;
        f[3][mask] = t1 + t2 + t3;
    }
    for (int i = 4; i <= n; ++i)
        for (int mask = 0; mask < 8; ++mask)
        {
            f[i][mask] = LLONG_MAX;
            if (!check(i, mask)) continue;
            int prev = mask >> 1;
            ll t = a[i];
            if (getBit(mask, 0)) t = -t;
            if (f[i - 1][prev] < LLONG_MAX)
                minimize(f[i][mask], f[i - 1][prev]);
            if (f[i - 1][prev + 4] < LLONG_MAX)
                minimize(f[i][mask], f[i - 1][prev + 4]);
            if (f[i][mask] < LLONG_MAX) f[i][mask] += t;
        }
}

void trace()
{
    int u = 0;
    for (int mask = 0; mask < 8; ++mask)
        if (f[n][u] > f[n][mask]) u = mask;
    for (int i = n; i > 3; --i)
    {
        if (getBit(u, 0)) a[i] = -a[i];
        int tmp = u >> 1;
        if (f[i][u] == f[i - 1][tmp] + a[i]) u = tmp;
        else u = tmp + 4;
    }
    if (getBit(u, 2)) a[1] = -a[1];
    if (getBit(u, 1)) a[2] = -a[2];
    if (getBit(u, 0)) a[3] = -a[3];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        if (n > 2) solve(), trace();
        else
        {
            if (a[1] < a[2]) a[1] = -a[1];
            if (a[1] > a[2]) a[2] = -a[2];
        }
        for (int i = 1; i <= n; ++i) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}