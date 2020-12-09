#include <bits/stdc++.h>

using namespace std;

int n;
set<long long> ans;

int main() {
    cin >> n;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i != 0) continue;
        int t = (n - 1) / i * i + 1;
        long long tmp = (long long)(1 + t) * (n / i) / 2;
        ans.insert(tmp);
        if (n / i == i) continue;
        t = n / i;
        t = (n - 1) / t * t + 1;
        tmp = (long long)(1 + t) * i / 2;
        ans.insert(tmp);
    }
    for (set<long long>::iterator i = ans.begin(); i != ans.end(); ++i) cout << (*i) << " ";
    return 0;
}
