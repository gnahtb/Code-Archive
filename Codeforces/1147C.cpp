#include <bits/stdc++.h>

using namespace std;

int n, a[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    a[n] = INT_MAX;
    for (int i = 1; i <= n; ++i)
        if (a[i] > a[i - 1]) {
            cout << (i <= n / 2 ? "Alice\n" : "Bob\n");
            break;
        }
    return 0;
}
