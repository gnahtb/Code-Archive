#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
 
#define fi first
#define se second

int n;
ll k;
vector<pii> a;

ll calc(ll mid, ll denom, ll init)
{
    long double ans = init;
    if (denom > mid) swap(denom, mid);
    for (int i = 1; i <= denom; ++i)
    {
        ans *= ll(i + mid);
        ans = round(ans / (long double)i);
        if (ans >= k) return k;
    }
    return ans;
}

bool check(ll mid)
{
    ll tmp = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        tmp += calc(mid, a[i].se, a[i].fi);
        if (tmp >= k) return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        if (t >= k) { cout << 0; return 0; }
        if (t > 0) a.push_back({t, n - i - 1});
    }
    ll left = 0, right= 1E18;
    while (left < right)
    {
        ll mid = (left + right) >> 1;
        if (check(mid)) right = mid;
        else left = mid + 1;
    } 
    cout << left + 1;
    return 0;
}
