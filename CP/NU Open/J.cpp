#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 2;

int n, m;
ll a[N], b[N];
vector<int> c;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> b[i];
    if (n < m) {
        cout << 0;
        return 0;
    }
    ll sum = 0;
    int j = 1, prej = 1;
    for (int i = 1; i <= m; ++i) {
        while (j <= n && sum < b[i]) {
            sum += a[j++];
        }
        if (sum == b[i]) {
            c.push_back(j - prej);
        } else {
            cout << 0;
            return 0;
        }
        prej = j;
        sum = 0;
    }
    sort(c.begin(), c.end());
    int k1 = c[0];
    int k2 = 0;
    set<int> ans;
    for (int i : c) k2 = __gcd(i - 1, k2);
    for (int i = 1; i <= k2; ++i)
        if (k2 % i == 0) ans.insert(i + 1);
    bool flag = true;
    for (int i : c)
        if (i > k1 && (i - 1) % k1 != 0) {
            flag = false;
            break;
        }
    if (flag) ans.insert(k1);
    cout << ans.size() << endl;
    for (int i : ans) cout << i << " ";
    return 0;
}