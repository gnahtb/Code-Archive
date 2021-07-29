#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        // bool flag = n % 2;
        int t = (n - n % 2) / 2 - 1;
        for (int i = 0; i < t; ++i) cout << "a";
        cout << "b";
        for (int i = 0; i <= t; ++i) cout << "a";
        if (n > 1 && n % 2 == 1) cout << "c";
        cout << endl;
    }
    return 0;
}