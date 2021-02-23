#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;

int n, m, minsat[N], maxsat[N];
string s, t;

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> n >> m >> s >> t;
    for (int i = 1, j = 1; i <= n && j <= m; ++i) {
        if (s[i - 1] == t[j - 1]) {
            minsat[j++] = i;
        }
    }
    for (int i = n, j = m; i > 0 && j > 0; --i) {
        if (s[i - 1] == t[j - 1]) {
            maxsat[j--] = i;
        }
    }
    int ans = 0;
    for (int i = 1; i < m; ++i) {
        ans = max(ans, maxsat[i + 1] - minsat[i]);
    }
    cout << ans;
    return 0;
}