#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

const int N_MAX = 5e5 + 5, Ai_MAX = 5e5 + 5;

int n, c, a[N_MAX], pre[N_MAX], suf[N_MAX];
int fmx[N_MAX];
vector<int> pos[Ai_MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1];
        if (a[i] == c) ++pre[i];
    }
    for (int i = n; i > 0; --i) {
        suf[i] = suf[i + 1];
        if (a[i] == c) ++suf[i];
    }
    int ans = pos[c].size();
    for (int i = 1; i <= 5e5; ++i) if (i != c) {
        fmx[sz(pos[i])] = 0;
        for (int j = sz(pos[i]) - 1; j >= 0; --j)
            fmx[j] = max(fmx[j + 1], suf[pos[i][j] + 1] + j + 1);
        for (int j = 0; j < sz(pos[i]); ++j) {
            int tmp = pre[pos[i][j] - 1] + fmx[j] - j;
            ans = max(ans, tmp);
        }
    }
    cout << ans << "\n";
    return 0;
}
