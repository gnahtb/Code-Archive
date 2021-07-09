#include <bits/stdc++.h>

using namespace std;

#define sqr(a) (a) * (a)

typedef long long ll;

const int N = 105;

int n;
ll k, a[N], ans = 0;
vector<int> v;

inline int ceil(int x, int y) { return (x + y - 1) / y; }

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        k += a[i];
        for (int j = 1; sqr(j) <= a[i]; ++j)
            v.push_back(j), v.push_back(ceil(a[i], j));
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i : v) {
        ll cur = 0;
        for (int j = 1; j <= n; ++j) cur += ceil(a[j], i);
        if (k / cur >= i) ans = max(ans, k / cur);
    }
    cout << ans << "\n";
    return 0;
}
