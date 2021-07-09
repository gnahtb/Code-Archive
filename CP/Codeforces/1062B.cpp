#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

const int LIM = 1E6 + 5;

int n, prime[LIM], x = 0, ans1 = 1, ans2;
vector<int> pw;

void sieve() {
    for (int i = 2; i <= 1E6; ++i) prime[i] = i;
    for (int i = 2; i <= 1000; ++i) if (prime[i] == i)
        for (int j = i * i; j <= 1E6; j += i) prime[j] = i;
}

int main() {
    ios_base::sync_with_stdio(false);
    sieve();
    cin >> n;
    int add = 0;
    while (n > 1) {
        int t = prime[n], cnt = 0;
        while (n % t == 0) ++cnt, n /= t;
        pw.push_back(cnt);
        x = max(x, cnt);
        ans1 *= t;
    }
    for (int i = 0; i <= 20; ++i)
        if ((1 << i) >= x) {
            for (int j : pw) if (j < (1 << i)) add = 1;
            ans2 = i + add;
            break;
        }
    cout << ans1 << " " << ans2 << "\n";
    return 0;
}
