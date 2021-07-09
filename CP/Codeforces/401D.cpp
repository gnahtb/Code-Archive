#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> n;
int m, pw10[20], used[10];
ll f[524288][100], ans = 0;

int get_bit(int state, int index) { return (state >> index) & 1; }

void solve()
{
    memset(f, 0, sizeof f);
    memset(used, -1, sizeof used);
    f[0][0] = 1;
    for (int mask = 1; mask < (1 << n.size()) - 1; ++mask)
    {
        int cnt = -1;
        for (int i = 0; i < int(n.size()); ++i) if (get_bit(mask, i)) ++cnt;
        for (int i = 0; i < int(n.size()); ++i)
            if (get_bit(mask, i) && used[n[i]] != mask)
            {
                used[n[i]] = mask;
                for (int rem = 0; rem < m; ++rem)
                {
                    int t = mask ^ (1 << i), u = (rem - pw10[cnt] * n[i] % m + m) % m;
                    f[mask][rem] += f[t][u];
                }
            }
    }
    for (int i = 0; i < int(n.size()); ++i)
        if (n[i] && used[n[i]] != 0)
        {
            used[n[i]] = 0;
            int t = ((1 << n.size()) - 1) ^ (1 << i), u = (m - pw10[n.size() - 1] * n[i] % m) % m;
            ans += f[t][u];
        }
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll tmp;
    scanf("%lld%d", &tmp, &m);
    while (tmp) n.push_back(tmp % 10LL), tmp /= 10LL;
    pw10[0] = 1;
    for (int i = 1; i < 19; ++i) pw10[i] = pw10[i - 1] * 10 % m;
    solve();
    printf("%lld\n", ans);
    return 0;
}
