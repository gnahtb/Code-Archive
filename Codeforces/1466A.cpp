#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x[n];
        for (int i = 0; i < n; ++i) cin >> x[i];
        set<int> app;
        app.clear();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                app.insert(x[j] - x[i]);
            }
        }
        cout << app.size() << "\n";
    }
    return 0;
}