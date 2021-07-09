#include <bits/stdc++.h>

using namespace std;

const int N = 1002;

int n, c[N], p[N], start[N];

int main() {
    // ios::sync_with_stdio(false);
    memset(start, -1, sizeof(start));
    while (true) {
        cin >> n;
        if (n == 0) break;
        for (int i = 1; i <= n; ++i) start[i] = -1;
        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            cin >> c[i] >> p[i];
            if (!flag) continue;
            int start_pos = i + p[i];
            if (start_pos < 1 || start_pos > n) {
                flag = false;
            } else {
                if (start[start_pos] < 0) {
                    start[start_pos] = c[i];
                } else {
                    flag = false;
                }
            }
        }
        if (flag) {
            for (int i = 1; i < n; ++i) cout << start[i] << " ";
            cout << start[n];
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}