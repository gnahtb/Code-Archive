#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int lim = 1E5 + 5;

int n, a[lim], c[lim], tmp = 0;
bool vis[lim];
ll ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]), ++c[a[i]];
    for (int i = 1; i <= 1E5; ++i) tmp += c[i] > 0;
    for (int i = 1; i < n; ++i)
    {
        --c[a[i]]; tmp -= c[a[i]] == 0;
        if (vis[a[i]]) continue;
        ans += ll(tmp);
        vis[a[i]] = true;
    }
    printf("%lld\n", ans);
    return 0;
}
