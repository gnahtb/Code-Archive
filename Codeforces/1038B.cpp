#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;
    if (n == 1) { cout << "No\n"; return 0; }
    for (int i = 2; i <= n; ++i) {
        int t = n / i, u = (t + 1) * t / 2 * i;
        if ((n * (n + 1) / 2 - u) % i == 0) {
            cout << "Yes\n" << t << " ";
            for (int j = i; j <= n; j += i) cout << j << " ";
            cout << "\n" << n - t << " ";
            for (int j = 1; j <= n; ++j)
                if (j % i != 0) cout << j << " ";   
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}
