#include <bits/stdc++.h>

using namespace std;

int n, p;

int main() {
    cin >> n >> p;
    for (int i = 1; i <= 200; ++i) {
        int n1 = n - p * i;
        int tmp = 0;
        for (int i = 0; i < 30; ++i)
            tmp += n1 >> i & 1;
        if (n1 >= i && i >= tmp) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
