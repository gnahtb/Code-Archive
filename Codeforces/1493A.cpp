#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int k, n;
        cin >> n >> k;
        int k1 = (k + 1) / 2;
        int t = n - k1;
        cout << t << "\n";
        for (int i = k1; i <= n; ++i) if (i != k) cout << i << " ";
        cout << "\n";
    }
    return 0;
}