#include <bits/stdc++.h>

using namespace std;

const int N = 12;

int test, n, a[N], pw3[N];

int getbit(int m, int i) {
    return m / pw3[i] % 3;
}

int main() {
    freopen("inp.txt", "r", stdin);
    cin >> test;
    pw3[0] = 1;
    for (int i = 1; i <= 10; ++i) pw3[i] = pw3[i - 1] * 3;
    while (test--) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        if (n == 1) {
            if (a[0] == 0)
                cout << "YES\n";
            else    
                cout << "NO\n";
            continue;
        }
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            vector<int> v;
            for (int j = 0; j < n; ++j)
                if (j != i) v.push_back(a[j]);
            for (int m = 0; m < pw3[n - 1]; ++m) {
                int sum = 0;
                for (int j = 0; j < n - 1; ++j)
                    if (getbit(m, j) == 1) sum += v[j];
                    else if (getbit(m, j) == 2) sum -= v[j];
                if (sum == a[i]) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}