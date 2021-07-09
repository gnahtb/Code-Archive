#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        char a[n][n];
        int i1 = -1, j1, i2, j2;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
                if (a[i][j] == '*') {
                    if (i1 == -1) {
                        i1 = i;
                        j1 = j;
                    } else {
                        i2 = i;
                        j2 = j;
                    }
                }
            }
        if (i1 == i2) {
            for (int i = 0; i < n; ++i) {
                if (i != i1) {
                    a[i][j1] = '*';
                    a[i][j2] = '*';
                    break;
                }
            }
        } else if (j1 == j2) {
            for (int j = 0; j < n; ++j) {
                if (j != j1) {
                    a[i1][j] = '*';
                    a[i2][j] = '*';
                    break;
                }
            }
        } else {
            swap(j1, j2);
            a[i1][j1] = '*';
            a[i2][j2] = '*';
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cout << a[i][j];
            cout << "\n";
        }
    }
    return 0;
}