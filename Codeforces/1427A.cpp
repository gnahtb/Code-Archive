#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        int a[100], sum = 0;
        for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
        if (sum == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            if (sum > 0) {
                sort(a, a + n, greater<int>());
            } else {
                sort(a, a + n);
            }
            for (int i = 0; i < n; ++i) cout << a[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}