#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define long long long
#define pw2(x) (1LL << (x))

int Q;
long cnt[70];

long getLevel(long x)
{
    for (long i = 0; i < 61; ++i)
        if (x < pw2(i + 1)) return i;
}

void update(int t, long x, long k)
{
    long l = getLevel(x);
    k %= pw2(l);
    ((cnt[l] += k) += pw2(l)) %= pw2(l);
    if (t == 1) return;
    for (long i = l + 1; i < 61; ++i)
        ((cnt[i] += k * pw2(i - l)) += pw2(i)) %= pw2(i);
}

void answer(long x)
{
    long l = getLevel(x);
    x += cnt[l];
    if (x < pw2(l)) x += pw2(l);
    if (x >= pw2(l + 1)) x -= pw2(l);
    while (x > 0)
    {
        long y = (x - cnt[l]) % pw2(l) + pw2(l);
        printf("%lld ", y);
        x /= 2; --l;
    }
    printf("\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &Q);
    memset(cnt, 0, sizeof cnt);
    while (Q--)
    {
        int T;
        long X, K;
        scanf("%d%lld", &T, &X);
        if (T < 3) scanf("%lld", &K), update(T, X, K);
        else answer(X);
    }
    return 0;
}
