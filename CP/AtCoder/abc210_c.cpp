#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 2;

int n, k, c[N], ans;
map<int, int> cnt;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> c[i], cnt[c[i]] = 0;
    int cur_dis = 0;
    for (int i = 0; i < k - 1; ++i)
        if (cnt[c[i]]++ == 0) ++cur_dis;
    for (int i = k - 1; i < n; ++i) {
        if (cnt[c[i]]++ == 0) ++cur_dis;
        ans = max(ans, cur_dis);
        if (--cnt[c[i - k + 1]] == 0) --cur_dis;
    }
    cout << ans;
    return 0;
}