#include <bits/stdc++.h>

using namespace std;

template <typename T> void maximize(T &a, T b) { if (a < b) a = b; }

typedef long long ll;

int n;
ll pb = INT_MAX, pr = INT_MAX, pp = INT_MAX, mb = 0, mr = 0, ans = 0;

void process(ll &px, ll &mx, ll x)
{
    if (px != INT_MAX)
    {
        ans += x - px;
        maximize(mx, x - px);
    }
    px = x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        char c;
        scanf("%d %c\n", &x, &c);
        if (c == 'B' || c == 'P') process(pb, mb, x);
        if (c == 'R' || c == 'P') process(pr, mr, x);
        if (c == 'P')
        {
            if (pp != INT_MAX)  ans += min(0LL, ll(x) - pp - mb - mr);
            pp = x; mb = 0; mr = 0;
        }
    }
    printf("%lld\n", ans);
}
