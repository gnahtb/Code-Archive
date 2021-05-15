#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int test, f[N + 2], g[N + 2];

void solve() {
    g[2] = 1;
    for (int i = 3; i <= N; ++i) {
        f[i] = 1;
        vector<int> div;
        div.clear();
        for (int j = 1; j * j <= i; ++j)
            if (i % j == 0) {
                div.push_back(j);
                if (i / j != j)
                    div.push_back(i / j);
            }
        for (int j : div) {
            if (j > 2 && i / j - 1 >= 2) {
                f[i] = max(f[i], g[i / j - 1] + 1);
            }
        }
        g[i] = f[i];
        if (i % 2 == 0 && i / 2 - 1 >= 2) {
            g[i] = max(g[i], g[i / 2 - 1] + 1);
        }
    }
}

int main() {
    solve();
    cin >> test;
    for (int itest = 1; itest <= test; ++itest) {
        int n;
        cin >> n;
        cout << "Case #" << itest << ": " << f[n] << endl;
    }
    return 0;
}