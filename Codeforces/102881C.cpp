#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int n, a[N];
set<int> whole, bit[30];
vector<int> ans;

void remove_id(int x) {
    whole.erase(whole.find(x));
    for (int i = 0; i < 30; ++i) {
        if ((a[x] >> i) & 1) {
            bit[i].erase(bit[i].find(x));
        }
    }
}

void go(int u) {
    ans.push_back(a[u]);
    remove_id(u);
    while (!whole.empty()) {
        int adj = INT_MAX;
        for (int i = 0; i < 30; ++i) {
            if ((a[u] >> i) & 1) {
                if (!bit[i].empty()) {
                    adj = min(adj, *bit[i].begin());
                }
            }
        }
        if (adj < n) {
            go(adj);
            continue;
        }
        go(*whole.begin());
    }
}

int main() {
    ios::sync_with_stdio(false);
    freopen("sorting.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        whole.insert(i);
        for (int j = 0; j < 30; ++j) {
            if ((a[i] >> j) & 1) {
                bit[j].insert(i);
            }
        }
    }
    go(0);
    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}