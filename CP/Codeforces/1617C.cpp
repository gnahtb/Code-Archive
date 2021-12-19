#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int test, n, a[N], b[N];
bool ok[N];

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> test;
    while (test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            ok[i] = false;
        }
        ok[n + 1] = false;
        sort(a + 1, a + n + 1);
        int cur = 1;
        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            while (cur <= n && ok[cur]) ++cur;
            if (a[i] <= n && !ok[a[i]]) {
                ok[a[i]] = true;
                b[i] = a[i];
            } else if (cur * 2 < a[i]) {
                b[i] = cur;
                ++cur;
            } else {
                flag = false;
                break;
            }
        }
        if (!flag) {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            if (a[i] != b[i]) ++ans;
        cout << ans << endl;
    }
    return 0;
}