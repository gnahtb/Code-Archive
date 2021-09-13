#include <bits/stdc++.h>

using namespace std;

const int M = 100, LIM = 1e6;

int test, m, p[M], n[M];
bool flag[LIM];

int cnt_pw(int x, int p) {
    int ret = 0;
    while (x % p == 0) ++ret, x /= p;
    return ret;
}

int main() {
    cin >> test;
    for (int itest = 1; itest <= test; ++itest) {
        cin >> m;
        int sum = 0;
        for (int i = 1; i <= m; ++i) {
            cin >> p[i] >> n[i];
            sum += p[i] * n[i];
        }
        for (int i = 0; i <= sum; ++i) flag[i] = false;
        flag[1] = true;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 1; i <= m; ++i) {
                if (sum / u >= p[i] && !flag[u * p[i]] && cnt_pw(u, p[i]) < n[i]) {
                    flag[u * p[i]] = true;
                    q.push(u * p[i]);
                }
            }
        }
        int ans = 0;
        for (int i = sum - 1; i; --i) if (flag[i]) {
            int tmp = 0;
            for (int j = 1; j <= m; ++j) tmp += (n[j] - cnt_pw(i, p[j])) * p[j];
            if (tmp == i) {
                ans = i;
                break;
            }
        }
        cout << "Case #" << itest << ": " << ans << "\n";
    }
    return 0;
}