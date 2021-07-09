#include <bits/stdc++.h>

using namespace std;

int k, q;
long double f[10005][1005];

void prep()
{
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for (int day = 1; day <= 10000; ++day)
        for (int i = 1; i <= k; ++i)
            f[day][i] = f[day - 1][i] * double(i) / double(k) + f[day - 1][i - 1] * (1 - double(i - 1) / double(k));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> k >> q;
    prep();
    while (q--)
    {
        double p;
        cin >> p; p /= double(2000);
        for (int ans = 1; ans <= 10000; ++ans)
            if (f[ans][k] - p >= 0) { cout << ans << "\n"; break; }
    }
    return 0;
}
