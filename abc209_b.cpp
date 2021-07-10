#include <bits/stdc++.h>

using namespace std;

int n, x;

int main() {
    cin >> n >> x;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        s += a - (i % 2);
    }
    cout << (s <= x ? "Yes" : "No");
}