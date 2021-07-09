#include <bits/stdc++.h>

using namespace std;

const int N = 502;

int n, p[N], tp[N], f[N], tf[N], ans = -1, l, r;
string s, t;

int proc() {
    p[0] = 0;
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + (s[i - 1] == '(' ? 1 : -1);
    for (int i = n - 1; i; --i)
        tp[i] = min(p[i], tp[i + 1]);
    f[0] = p[n];
    tf[0] = INT_MAX;
    int cur = 0;
    for (int i = 1, j = 0; i <= n; ++i, ++j) {
        if (j > 0) {
            f[j] = f[j - 1] + (s[j - 1] == '(' ? 1 : -1);
            tf[j] = min(tf[j - 1], f[j]);
        }
        int tmp = min(tp[i], tf[j]);
        if (tmp >= p[i - 1] && f[j] == p[i - 1]) ++cur;
    }
    return cur;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;
    t = s + s;
    int tmp = proc();
    if (tmp > ans) {
        ans = tmp;
        l = r = 1;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            swap(s[i - 1], s[j - 1]);
            tmp = proc();
            if (tmp > ans) {
                ans = tmp;
                l = i;
                r = j;
            }
            swap(s[i - 1], s[j - 1]);
        }
    cout << ans << "\n" << l << " " << r << "\n";
    return 0;
}
