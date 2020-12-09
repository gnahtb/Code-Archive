#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int n, a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    long long sum = 0;
    bool chk = false;
    int cnt0 = 0;
    for (int i = 0; i < n; ++i) cnt0 += a[i] == 0;
    if (cnt0 > 1) {
        cout << "cslnb\n";
        return 0;        
    }
    for (int l = 0, r = 0; r < n; l = r) {
        while (r < n && a[l] == a[r]) ++r;
        if (r - l > 1) {
            if (chk || r - l > 2) {
                cout << "cslnb\n";
                return 0;
            } else chk = true;
        }
        for (int i = l; i < r; ++i) sum += a[i] - i;
    }
    for (int i = 0; i < n - 1; ++i)
        if (a[i] == a[i + 1]) {
            if (i == 0 && a[i] > 0)
                break;
            if (a[i - 1] + 1 == a[i]) {
                cout << "cslnb\n";
                return 0;
            }
            break;
        }
    cout << (sum % 2 == 0 ? "cslnb\n" : "sjfnb\n");
    return 0;
}
