#include <bits/stdc++.h>

using namespace std;

const int N = 102;

int test, n, a[N];

void Solve() {
    for (int i = 1; i <= n; ++i)
        if (a[i] % 2 == 0) {
            cout << "1\n";
            cout << i << "\n";
            return;
        }
    if (n < 2) {
        cout << "-1\n";
        return;
    }
    cout << "2\n1 2\n";
}

int main() {
    cin >> test;
    while (test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        Solve();
    }
    return 0;
}
