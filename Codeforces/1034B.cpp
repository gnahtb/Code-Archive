#include <bits/stdc++.h>

using namespace std;

long long a, b, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (a == 1)
        cout << b / 6 * 6 + max(b % 6 - 3, 0LL) * 2 << "\n";
    else if (a == 2)
        cout << (b > 3 ? b == 7 ? 12 : a * b : b == 3 ? 4 : 0) << "\n";
    else if (a == 3 && b == 3)
        cout << "8\n";
    else
        cout << a * b - a * b % 2 << "\n";
    return 0;
}
