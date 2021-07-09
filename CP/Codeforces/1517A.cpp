#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int test;
ll n;

int main() {
    cin >> test;
    while (test--) {
        cin >> n;
        if (n % 2050 == 0) {
            n /= 2050;
            ll sum = 0;
            while (n > 0) sum += n % 10, n /= 10;
            cout << sum << "\n";
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}