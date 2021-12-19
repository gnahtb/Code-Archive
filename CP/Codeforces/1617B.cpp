#include <bits/stdc++.h>

using namespace std;

int test;

int main() {
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            int c = 1;
            int a = (n - 1) / 2;
            int b = n - 1 - a;
            cout << a << " " << b << " " << c << endl;
        } else {
            int c = 1;
            int a = (n - 1) / 2 - 1;
            int b = n - 1 - a;
            if (a % 2 == 0) {
                --a;
                ++b;
            }
            cout << a << " " << b << " " << c << endl;
        }
    }
    return 0;
}