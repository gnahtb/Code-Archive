#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 2;

int n, q, a[N];
set<int> evens, odds;
long long sum = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("orxor.in", "r", stdin);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (a[i] % 2) {
            if (a[i] > 1) {
                odds.insert(i);
            }
        } else {
            evens.insert(i);
        }
    }
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        --l;
        vector<set<int>::iterator> toremove;
        if (t == 2) {
            toremove.clear();
            for (set<int>::iterator it = odds.lower_bound(l); it != odds.end() && *it < r; ++it) {
                sum -= a[*it] - 1;
                toremove.push_back(it);
            }
            for (set<int>::iterator i : toremove) odds.erase(i);
        }
        toremove.clear();
        for (set<int>::iterator it = evens.lower_bound(l); it != evens.end() && *it < r; ++it) {
            if (t == 1) {
                sum += (a[*it] | (a[*it] - 1)) - a[*it];
                a[*it] |= a[*it] - 1;
            } else {
                sum += (a[*it] ^ (a[*it] - 1)) - a[*it];
                a[*it] ^= a[*it] - 1;
            }
            odds.insert(*it);
            toremove.push_back(it);
        }
        for (set<int>::iterator i : toremove) evens.erase(i);
        cout << sum << "\n";
    }
    return 0;
}