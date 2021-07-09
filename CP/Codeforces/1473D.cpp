#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 2;
const int oo = 1e9;

int n, m, a[N], amaxleft[N], aminleft[N], amaxright[N], aminright[N];
string sn;

int main() {
    ios::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> m >> sn;
        for (int i = 1; i <= n; ++i)
            if (sn[i - 1] == '+') a[i] = a[i - 1] + 1;
            else a[i] = a[i - 1] - 1;
        aminleft[0] = amaxleft[0] = 0;
        for (int i = 1; i <= n; ++i) {
            aminleft[i] = min(aminleft[i - 1], a[i]);
            amaxleft[i] = max(amaxleft[i - 1], a[i]);
        }
        aminright[n + 1] = oo;
        amaxright[n + 1] = -oo;
        for (int i = n; i; --i) {
            aminright[i] = min(aminright[i + 1], a[i]);
            amaxright[i] = max(amaxright[i + 1], a[i]);
        }            
        while (m--) {
            int l, r;
            cin >> l >> r;
            int min1 = aminleft[l - 1];
            int max1 = amaxleft[l - 1];
            int min2 = aminright[r + 1] - (a[r] - a[l - 1]);
            int max2 = amaxright[r + 1] - (a[r] - a[l - 1]);
            int mint = min(min1, min2);
            int maxt = max(max1, max2);
            cout << (maxt - mint + 1) << "\n";
        }
    }
    return 0;
}