#include <bits/stdc++.h>

using namespace std;

const int N = 102;

int test, n, a[N];

int main() {
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        bool watered = true;
        int ans = 1;
        for (int i = 1; i <= n; ++i)
            if (a[i] == 0) {
                if (watered)
                    watered = false;
                else {
                    ans = -1;
                    break;
                }
            } else {
                if (i > 1 && watered) {
                    ans += 5;
                } else {
                    ans += 1;
                }
                watered = true;
            }
        cout << ans << endl;
    }   
    return 0;
}