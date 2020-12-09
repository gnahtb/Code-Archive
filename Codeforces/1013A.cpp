#include <bits/stdc++.h>

using namespace std;

int n, s = 0, t = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s += x;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        t += x;
    }
    cout << (t <= s ? "Yes" : "No") << "\n";
    return 0;
}
