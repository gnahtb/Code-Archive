#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, x, y;
    cin >> n >> a >> x >> y;
    cout << (min(n, a) * x + max(0, n - a) * y);
    return 0;
}