#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

const int maxN = 1E5 + 5;

int n, d, a[maxN], ans = 0;
ll s[maxN], l[maxN];

void prep()
{
    ll cur = LLONG_MIN;
    memset(s, 0, sizeof s);
    memset(l, 0, sizeof l);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + ll(a[i]);
    for (int i = n; i > 0; --i)
    {
        cur = max(cur, s[i]);
        l[i] = d - cur;
        if (l[i] < 0) { puts("-1"); exit(0); }
    }
}

void solve()
{
    int pos = 0;
    ll dif = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != 0) { pos = i; continue; }
        if (s[i] + dif >= 0) continue;
        dif = l[pos]; ++ans;
        if (s[i] + dif < 0) { puts("-1"); exit(0); }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    prep();
    solve();
    printf("%d\n", ans);
    return 0;
}
