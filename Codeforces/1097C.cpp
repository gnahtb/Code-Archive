#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

const int LIM = 1e6 + 5, DIF = 5e5 + 3;
// const int LIM = 20, DIF = 10;

int n, ans = 0;
bool vis[LIM];
vector<int> sum[LIM];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        int cur_sum = 0, min_pos = 0;
        for (int i = 0; i < sz(s); ++i) {
            cur_sum += s[i] == '(' ? 1 : -1;
            min_pos = min(min_pos, cur_sum);
        }
        sum[cur_sum + DIF].push_back(min_pos);
    }
    for (int x = 1; x <= 5e5; ++x) {
        int i = x + DIF, j = -x + DIF;
        if (vis[i]) continue;
        vis[i] = true;
        int tmp = 0, tmp1 = 0;
        for (int v : sum[i]) if (v >= 0) ++tmp1;
        for (int v : sum[j]) if (v + x >= 0) ++tmp;
        ans += min(tmp1, tmp);
    }
    int tmp = 0;
    for (int v : sum[DIF]) if (v >= 0) ++tmp;
    ans += tmp / 2;
    cout << ans << "\n";
    return 0;
}
