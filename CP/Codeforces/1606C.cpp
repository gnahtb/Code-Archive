#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 22;

int test, n, w[N + 2];
ll k;
bool a[N + 2];

int main() {
    cin >> test;
    while (test--) {
        cin >> n >> k;
        memset(a, false, sizeof(a));
        for (int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            a[t] = true;
        }
        ll cur = 1;
        for (int i = 0; i < N; ++i) {
            if (a[i]) cur = 1;
            w[i] = cur;
            cur *= 10;
        }
        ll sum = 0;
        for (int len = 0; len <= N; ++len) {
            if ((sum + w[len]) * 9 > k) {
                for (int j = len; j >= 0; --j) {
                    for (int i = j == len; i < 10; ++i) {
                        if (sum * 9 + 1LL * i * w[j] > k) {
                            cout << i;
                            k -= 1LL * i * w[j];
                            if (j > 0) sum -= w[j - 1];
                            break;
                        }
                    }
                }
                break;
            } else {
                sum += w[len];
            }
        }
        cout << endl;
    }
    return 0;
}