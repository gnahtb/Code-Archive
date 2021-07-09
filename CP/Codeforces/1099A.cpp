#include <bits/stdc++.h>

using namespace std;

int w, h, u1, d1, u2, d2;

int main() {
    ios::sync_with_stdio(false);
    cin >> w >> h >> u1 >> d1 >> u2 >> d2;
    if (d1 < d2) swap(d1, d2), swap(u1, u2);
    for (int i = h; i; --i) {
        w += i;
        if (i == d1) w = max(w - u1, 0);
        if (i == d2) w = max(w - u2, 0);
    }
    cout << w << "\n";
    return 0;
}
