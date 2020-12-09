#include <bits/stdc++.h>

using namespace std;

int test, a, b, c;

bool GetBit(int b, int i) {
    return b >> i & 1;
}

int main() {
    cin >> test;
    while (test--) {
        cin >> a >> b >> c;
        int ans = 0;
        for (int mk = 1; mk < 256; ++mk) {
            int a1 = 0, b1 = 0, c1 = 0;
            for (int i = 0; i < 8; ++i) {
                if (GetBit(mk, i)) {
                    a1 += GetBit(i, 0);
                    b1 += GetBit(i, 1);
                    c1 += GetBit(i, 2);
                }
            }
            if (a1 <= a && b1 <= b && c1 <= c) {
                ans = max(ans, __builtin_popcount(mk));
            }
        }
        cout << (ans - 1) << "\n";
    }
    return 0;
}
