#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;

const int maxN = 1E5 + 5;

int n, c, a[maxN];
ll s[maxN], f[maxN];
priority_queue<ii, vector<ii>, greater<ii>> q;

void solve()
{
    memset(f, 0, sizeof f);
    memset(s, 0, sizeof s);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + ll(a[i]);
    for (int i = 1; i <= n; ++i)
    {
        f[i] = f[i - 1] + ll(a[i]);
        q.push({a[i], i});
        if (i >= c)
        {
            while (!q.empty() && q.top().se <= i - c) q.pop();
            f[i] = min(f[i], f[i - c] + s[i] - s[i - c] - ll(q.top().fi));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    solve();
    printf("%lld\n", f[n]);
    return 0;
}
