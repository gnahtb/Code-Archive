#include <bits/stdc++.h>

using namespace std;

#define sqr(a) (a) * (a)

const int limit = 1E6 + 5;

int f[limit], t, x, k, p;
vector<int> u;

void sieve()
{
    for (int i = 2; i < limit; ++i) f[i] = i;
    for (int i = 2; sqr(i) < limit; ++i) if (f[i] == i)
        for (int j = sqr(i); j < limit; j += i) f[j] = i;
}

void fact(int param)
{
    u.clear();
    while (param > 1)
    {
        int d = f[param]; u.push_back(d);
        while (param % d == 0) param /= d;
    }
}

int calc(int param)
{
    int w[10], r = 0;
    memset(w, 0, sizeof w);
    for (int mask = 0; mask < 1 << (int)u.size(); ++mask)
    {
        int cnt = 0, pd = 1;
        for (int i = 0; i < (int)u.size(); ++i)
            if ((mask >> i) & 1) ++cnt, pd *= u[i];
        w[cnt] += param / pd;
    }
    for (int i = 0; i <= (int)u.size(); ++i)
        if ((i & 1) == 0) r += w[i]; else r -= w[i];
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    sieve();
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &x, &p, &k);
        fact(p);
        int L = calc(x), low = x + 1, high = 1E9, ans = -1;
        while (low <= high)
        {
            int med = (low + high) >> 1, R = calc(med);
            if (R - L >= k)
            {
                if (R - L == k) ans = med;
                high = med - 1;
            }
            else low = med + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
