#include <bits/stdc++.h>

using namespace std;

int main() {
    char x1, x2, x3, x4;
    cin >> x1 >> x2 >> x3 >> x4;
    x1 -= '0';
    x2 -= '0';
    x3 -= '0';
    x4 -= '0';
    if (x1 == x2 && x2 == x3 && x3 == x4) {
        cout << "Weak";
        return 0;
    }
    if (x2 == (x1 + 1) % 10 && x3 == (x2 + 1) % 10 && x4 == (x3 + 1) % 10) {
        cout << "Weak";
        return 0;
    }
    cout << "Strong";
    return 0;
}