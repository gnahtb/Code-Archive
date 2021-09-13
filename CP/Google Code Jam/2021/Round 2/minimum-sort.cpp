#include <bits/stdc++.h>

using namespace std;

int test, n;

int main() {
    cin >> test >> n;
    for (int itest = 1; itest <= test; ++itest) {
        for (int i = 1; i < n; ++i) {
            cout << "M " << i << " " << n << endl;
            int pos;
            cin >> pos;
            if (pos != i) {
                cout << "S " << i << " " << pos << endl;
            }
        }
        cout << "D" << endl;
        int ver;
        cin >> ver;
        if (ver < 0) {
            return 0;
        }
    }
    return 0;
}