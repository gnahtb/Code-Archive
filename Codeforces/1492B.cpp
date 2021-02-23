#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int t, n, p[N];
bool vis[N];

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            vis[i] = false;
        }
        int j = n;
        for (int i = n; i; --i) {
            if (vis[i]) continue;
            int j1 = j;
            while (p[j1] != i) --j1;
            for (int k = j1; k <= j; ++k) {
                cout << p[k] << " ";
                vis[p[k]] = true;
            }
            j = j1 - 1;
        }
        cout << "\n";
    }
    return 0;
}