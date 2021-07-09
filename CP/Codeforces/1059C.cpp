#include <bits/stdc++.h>

using namespace std;

int n;

void solve(int n, int p) {
    if (n < 4) {
        if (n == 1) cout << p;
        else if (n == 2) cout << p << " " << p * 2;
        else cout << p << " " << p << " " << p * 3;
        return;
    }
    for (int i = 1; i <= n - n / 2; ++i) cout << p << " ";
    solve(n / 2, p * 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    solve(n, 1);
    return 0;
}
