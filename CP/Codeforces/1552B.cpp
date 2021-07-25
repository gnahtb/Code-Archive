#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int test, n, r[N][5], id[N];

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> test;
    while (test--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) cin >> r[i][j];
            id[i] = i;
        }
        sort(id, id + n, [&](int x, int y) {
            int cnt = 0;
            for (int j = 0; j < 5; ++j)
                if (r[x][j] > r[y][j]) ++cnt;
            return cnt > 2;
        });
        bool flag = true;
        for (int i = 0; i < n - 1; ++i) {
            int x = id[i];
            int y = id[n - 1];
            int cnt = 0;
            for (int j = 0; j < 5; ++j)
                if (r[x][j] > r[y][j]) ++cnt;
            if (cnt < 3) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << (id[n - 1] + 1) << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    return 0;
}