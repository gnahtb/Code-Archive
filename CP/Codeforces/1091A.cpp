#include <bits/stdc++.h>

using namespace std;

int main() {
    int y, b, r;
    cin >> y >> b >> r;
    for (int x = 100; x > 0; --x)
        if (x <= y && x + 1 <= b && x + 2 <= r) {
            cout << x + x + x + 3 << "\n";
            break;
        }
    return 0;
}
