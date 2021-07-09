#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll p, k;
vector<ll> a;

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%lld%lld", &p, &k);
    while (p)
    {
        ll rem = (p % k + k) % k;
        a.push_back(rem);
        p = (rem - p) / k;
    }
    if (p > 0) a.push_back(p);
    printf("%lld\n", ll(a.size()));
    for (ll u: a) printf("%lld ", u);
    printf("\n");
    return 0;
}
