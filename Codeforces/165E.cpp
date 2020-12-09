#include <cstring>
#include <iostream>

using namespace std;

const int L = 4194304;
const int N = 1000000;

int n, a[N], d[L];

inline int getbit(int m, int i) { return m >> i & 1; }

void DFS(int u, int x) {
    d[u] = x;
    for (int i = 0; i < 22; ++i)
        if (getbit(u, i) && d[u ^ 1 << i] < 0) DFS(u ^ 1 << i, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(d, -1, sizeof d);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (d[L - a[i] - 1] < 0) DFS(L - a[i] - 1, a[i]);
    }
    for (int i = 0; i < n; ++i) cout << d[a[i]] << " ";
    return 0;
}
