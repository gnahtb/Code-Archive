#include <bits/stdc++.h>

using namespace std;

int test;

int main() {
    cin >> test;
    while (test--) {
        long long r, b, d;
        cin >> r >> b >> d;
        if (d == 0) {
            if (r == b) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }
        long long dif = abs(r - b) / d;
        if (abs(r - b) % d > 0) ++dif;
        if (min(r, b) >= dif) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}