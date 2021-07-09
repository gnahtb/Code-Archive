#include <cstring>
#include <iostream>
 
using namespace std;
 
typedef long long ll;
 
const int N = 1048576;
 
int t, n, a[N], f[N];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        ll ans = 0;
        memset(a, 0, sizeof a);
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int v;
            cin >> v;
            ans += (ll)a[v]++;
        }
        memcpy(f, a, sizeof f);
        for (int i = 0; i < 20; ++i)
            for (int m = 0; m < N; ++m)
                if (m >> i & 1) f[m] += f[m ^ 1 << i];
        for (int m = 0; m < N; ++m)
            ans += a[m] * (f[m] - a[m]);
        cout << ans << "\n";
    }
    return 0;
}