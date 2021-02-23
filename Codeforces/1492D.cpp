#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;

int a, b, k, x[N], y[N];

int main() {
    cin >> a >> b >> k;
    if (b == 1) {
        if (k > 0) {
            cout << "No";
        } else {
            cout << "Yes\n";
            cout << 1;
            for (int i = 1; i < a + b; ++i) cout << 0;
            cout << "\n";
            cout << 1;
            for (int i = 1; i < a + b; ++i) cout << 0;
        }
        return 0;
    }
    if (a == 0) {
        if (k > 0) {
            cout << "No";
        } else {
            cout << "Yes\n";
            for (int i = 1; i <= a + b; ++i) cout << 1;
            cout << "\n";
            for (int i = 1; i <= a + b; ++i) cout << 1;
        }
        return 0;
    }
    if (k >= a + b - 1) {
        cout << "No";
        return 0;
    }
    x[a + b] = y[a + b] = x[k + 1] = y[1] = 1;
    int tmp = 2;
    for (int i = 2; tmp < b && i < a + b; ++i)
        if (i != k + 1) {
            x[i] = y[i] = 1;
            ++tmp;
        }
    cout << "Yes\n";
    for (int i = a + b; i; --i) cout << x[i];
    cout << "\n";
    for (int i = a + b; i; --i) cout << y[i];
    return 0;
}