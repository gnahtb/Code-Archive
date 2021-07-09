#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxN = 1E5 + 5;

int n, a[maxN], l;
ll t1 = 0, t2 = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (l = 0; l < n; ++l)
        if (a[l] - 1 > 1000000 - a[l]) break;
    int b = 1;
    for (int i = 0; i < l; ++i) t1 += ll(a[i] - b), b = a[i];
    b = 1000000;
    for (int i = n - 1; i >= l; --i) t2 += ll(b - a[i]), b = a[i];
    cout << max(t1, t2) << "\n";
    return 0;
}
