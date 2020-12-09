#include <bits/stdc++.h>

using namespace std;

int n, k, ans = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    if (n <= k * 2 + 1) {
        cout << "1\n" << (n + 1) / 2 << "\n";
        return 0;
    }
    if (n % (k * 2 + 1) > k || n % (k * 2 + 1) == 0) {
        cout << n / (k * 2 + 1) + (n % (k * 2 + 1) > 0) << "\n";
        int t = k + 1;
        while (n > 0) { 
            cout << t << " ";
            t += 2 * k + 1;
            n -= 2 * k + 1;
        }
        return 0;
    }
    for (int t = 1; t < k + 1; ++t) {
        int x = n - t - k;
        if (x % (k * 2 + 1) > k || x % (k * 2 + 1) == 0) {
            cout << 1 + x / (k * 2 + 1) + (x % (k * 2 + 1) > 0) << "\n";
            cout << t << " ";
            int y = t + k * 2 + 1;
            while (x > 0) {
                cout << y << " ";
                y += 2 * k + 1;
                x -= 2 * k + 1;
            }
            return 0;
        }
    }
    return 0;
}
