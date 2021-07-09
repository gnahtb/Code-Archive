#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull mul(ull x, ull y, ull z) {
    if (y == 0) return 0;
    ull t = mul(x, y / 2, z);
    (t *= 2) %= z;
    if (y % 2 != 0) (t += x) %= z;
    return t;
}

ull power(ull x, ull y, ull z) {
    if (y == 0) return 1 % z;
    ull t = power(x, y / 2, z);
    t = mul(t, t, z);
    if (y % 2 != 0) t = mul(t, x, z);
    return t;
}

// Rabin - Miller primality test
bool check(ull x) {
    if (x < 4) return (x == 2 || x == 3);

    srand(time(nullptr));

    vector<ull> pw;
    ull tx = x - 1;
    pw.clear();
    while (tx % 2 == 0) {
        pw.push_back(tx);
        tx /= 2;
    }
    pw.push_back(tx);

    int REP = 100;
    while (REP--) {
        ull a = rand() % (x - 3) + 2;
        bool flag = false;
        for (ull i : pw) {
            ull t = power(a, i, x);
            if (t == x - 1) {
                flag = true;
                break;
            }
        }
        if (power(a, tx, x) == 1) flag = true;
        if (!flag) return false;
    }

    return true;
}

int t;
ull n;

int main() {
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n;
        cout << (check(n) ? "YES\n" : "NO\n");
    }

    return 0;
}