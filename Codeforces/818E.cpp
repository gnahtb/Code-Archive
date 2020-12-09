#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define fi first
#define se second
#define sqr(a) (a) * (a)

typedef long long ll;
typedef pair<int, int> pii;

const int maxN = 1E5 + 5;

int n, k, a[maxN][10];
ll ans = 0;
vector<pii> p;

bool check(int L, int R)
{
    for (int i = 0; i < int(p.size()); ++i)
        if (a[R][i] - a[L][i] < p[i].se) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &k);
    while (k > 1)
    {
        int x = k, y = 0;
        for (int d = 2; sqr(d) <= k; ++d)
            if (x % d == 0) { x = d; break; }
        while (k % x == 0) k /= x, ++y;
        p.push_back({x, y});
    }
    memset(a, 0, sizeof a);
    for (int i = 1; i <= n; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        for (int j = 0; j < int(p.size()); ++j)
        {
            int pw = 0;
            while (tmp % p[j].fi == 0) tmp /= p[j].fi, ++pw;
            a[i][j] = a[i - 1][j] + pw;
        }
    }
    for (int j = 0; j < int(p.size()); ++j) a[n + 1][j] = a[n][j];
    for (int i = 0; i <= n; ++i)
    {
        int L = i + 1, R = n + 1, pos = -1;
        while (L <= R)
        {
            int mid = (L + R) >> 1;
            if (check(i, mid)) pos = mid, R = mid - 1;
            else L = mid + 1;
        }
        if (pos >= 0) ans += ll(n - pos + 1);
    }
    printf("%lld\n", ans);
    return 0;
}
