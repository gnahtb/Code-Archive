#include <bits/stdc++.h>

using namespace std;

const int N = 5002;

int n, m, ans[N];
map<int, int> fre;

int main() {
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j)
            if (i + j <= n) ++cnt;
    }
    if (cnt < m) {
        cout << "-1\n";
        return 0;
    }
    int cur = 0;
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int tmp = cnt + (i - 1) / 2;
        if (tmp > m) break;
        else {
            ans[i] = i;
            ++cur;
            cnt = tmp;
        }
    }
    m -= cnt;
    for (int i = 1; i <= cur; ++i) {
        for (int j = i + 1; j <= cur; ++j) if (i + j > cur) {
            ++fre[ans[i] + ans[j]];
        }
    }
    for (pair<int, int> i : fre) if (i.second == m) {
        ans[++cur] = i.first;
        break;
    }
    for (int i = cur + 1; i <= n; ++i)
        ans[i] = 10000000 + 6000 * (i - cur);
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    return 0;
}
