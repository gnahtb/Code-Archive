#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a[102], cnt[102];
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            ++cnt[a[i]];
        }
        for (int i = 1; i <= 100; ++i)
            if (cnt[i] == 1) {
                bool ok = false;
                for (int j = 1; j <= n; ++j)
                    if (i == a[j]) {
                        cout << j << "\n";
                        ok = true;
                        break;
                    }
                if (ok) break;
            }
    }
    return 0;
}