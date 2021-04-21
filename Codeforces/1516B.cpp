#include <bits/stdc++.h>

using namespace std;

const int N = 2002;

int test, n, a[N], sx[N];

bool chec() {
    for (int i = 1; i <= n; ++i)
        if ((sx[n] ^ sx[i]) == sx[i]) return true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if ((sx[n] ^ sx[i]) == sx[j] && (sx[i] ^ sx[j]) == sx[j]) return true;
        }
    }
    return false;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i], sx[i] = sx[i - 1] ^ a[i];
        cout << (chec() ? "YES\n" : "NO\n");
    }
    return 0;
}