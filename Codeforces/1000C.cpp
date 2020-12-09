#include <bits/stdc++.h>

using namespace std;

#define sz(a) int(a.size())

typedef long long ll;

struct TSegment { ll l, r; };

const int maxN = 2E5 + 5;

int n, sum[maxN * 2];
ll cnt[maxN];
vector<ll> v;
vector<TSegment> seg;

int getIndex(ll x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }

void solve()
{
    memset(sum, 0, sizeof sum);
    memset(cnt, 0, sizeof cnt);
    for (TSegment i: seg) ++sum[getIndex(i.l)], --sum[getIndex(i.r)];
    for (int i = 1; i < sz(v); ++i) sum[i] += sum[i - 1];
    for (int i = 1; i < sz(v); ++i) cnt[sum[i - 1]] += v[i] - v[i - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        ll l, r;
        scanf("%lld%lld", &l, &r);
        seg.push_back({l, r + 1});
        v.push_back(l); v.push_back(r + 1);
    }
    sort(v.begin(), v.end());
    v.resize(distance(v.begin(), unique(v.begin(), v.end())));
    solve();
    for (int i = 1; i <= n; ++i) printf("%lld ", cnt[i]);
    return 0;
}
