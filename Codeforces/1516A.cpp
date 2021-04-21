#include <bits/stdc++.h>

using namespace std;

int test;

int main() {
    cin >> test;
    while (test--) {
        int n, k, a[102];
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int j = 1;
        while (k--) {
            while (j < n && a[j] == 0) ++j;
            if (j == n) break;
            --a[j];
            ++a[n];
        }
        for (int i = 1; i <= n; ++i) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}