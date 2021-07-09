#include <bits/stdc++.h>

using namespace std;

template<typename T> void maximize(T &a, T b) { if (a < b) a = b; }

typedef long long ll;

ll n, k, M, D, ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> M >> D;
    ans = n / M / k * M;
    if ((n / M) % k > 0) ans += M;
    for (ll i = 0; i <= D; ++i)
    {
        if (n / k < i) break;
        if (i > 0 && n / (i * k) <= M) maximize(ans, n / (i * k) * i);
        if (i == D) break;
        if (i == 0 || n / (i * k) > M)
        {
            ll L = 1, R = k - 1, tmp = 0;
            while (L <= R)
            {
                ll mid = (L + R) / 2;
                if (n / (i * k + mid) <= M) tmp = mid, R = mid - 1;
                else L = mid + 1;
            }
            if (tmp) maximize(ans, n / (i * k + tmp) * (i + 1));
        }
        else maximize(ans, n / (i * k + 1) * (i + 1));
    }
    cout << ans << "\n";
    return 0;
}
