#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int t, n, x[N], y[N];
bool chk[N];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        memset(chk, false, sizeof(chk));
        for (int i = 1; i <= n; ++i) {
            cin >> x[i];
            y[i] = x[i];
            if (x[i] == x[i - 1]) {
                ++y[i];
                chk[i] = true;
            } else if (y[i] == y[i - 1]) {
                ++y[i];
                chk[i] = true;
            }
        }
        if (!chk[n]) ++y[n];
        set<int> app;
        app.clear();
        for (int i = 1; i <= n; ++i)
            app.insert(y[i]);
        cout << app.size() << "\n";
    }
    return 0;
}