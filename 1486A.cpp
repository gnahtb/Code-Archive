#include <bits/stdc++.h>

using namespace std;

int t;
long long h[102];

void solve() {
    long long n;
    cin >> n;
    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        cin >> h[i];
    }
    for (long long i = 0; i < n; ++i) {
        sum += h[i] - i;
        if (sum < 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}