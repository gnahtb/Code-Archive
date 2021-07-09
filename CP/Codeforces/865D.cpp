#include <climits>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

const ll inf = 1E9;

int n;
ll ans = 0;
priority_queue<ll, vector<ll>, greater<ll>> u, v;

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        ll p, t1 = inf, t2 = inf;
        scanf("%lld", &p);
        if (!u.empty()) t1 = u.top();
        if (!v.empty()) t2 = v.top();
        if (p <= t1 && p <= t2) { u.push(p); continue; }
        if (p - t1 >= p - t2)
        {
            ans += p - t1;
            v.push(p); u.pop();
        }
        else
        {
            ans += p - t2;
            u.push(t2); v.pop(); v.push(p);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
