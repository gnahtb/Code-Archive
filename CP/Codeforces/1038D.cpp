#include <bits/stdc++.h>

using namespace std;

const int N = 5E5 + 5;

int n, a[N];
bool chkneg = false, chkpos = false;
long long ans = LLONG_MIN;

void solve1() {
    long long sum = 0, sub = 0, s1 = 0;
    for (int i = 1; i <= n; ++i)
        sum += (long long)a[i], sub -= (long long)a[i], s1 += abs(a[i]);
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, sum - (long long)a[i] * 2);
        ans = max(ans, sub + (long long)a[i] * 2);
    }
    if (chkpos && chkneg) ans = max(ans, s1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n == 1) {
        int a;
        cin >> a;
        cout << a << "\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        chkpos |= (a[i] >= 0);
        chkneg |= (a[i] <= 0);
    }
    solve1();
    cout << ans << "\n";
    return 0;
}
