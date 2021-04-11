#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        int b[n + 2];
        long long sum = 0;
        for (int i = 0; i < n + 2; ++i) {
            cin >> b[i];
            sum += b[i];
        }
        sort(b, &(b[n + 2]));
        bool ok = false;
        for (int i = 0; i < n + 2; ++i) {
            int isum = i == n + 1 ? n : n + 1;
            long long tmp = sum - b[i] - b[isum];
            if (b[isum] == tmp) {
                for (int j = 0; j < n + 2; ++j)
                    if (j != i && j != isum) {
                        cout << b[j] << " ";
                    }
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "-1";
        }
        cout << "\n";
    }
}