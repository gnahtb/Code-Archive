#include <bits/stdc++.h>

using namespace std;

int n, s;

int main() {
    cin >> n >> s;
    int ans = s / n;
    if (s % n > 0) ++ans;
    cout << ans << "\n";
}
