#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 2;

int n, q;
vector<int> v[N << 2];
bitset<N> ans;

#define md ((cl + cr) >> 1)
#define nx (i << 1)
void ins(int l, int r, int x, int cl, int cr, int i = 1) {
    if (cl > r || cr < l) return;
    if (l <= cl && cr <= r) {
        v[i].push_back(x);
        return;
    }
    ins(l, r, x, cl, md, nx);
    ins(l, r, x, md + 1, cr, nx + 1);
}

void dfs(bitset<N> b, int cl, int cr, int i = 1) {
    for (int x : v[i]) {
        b |= (b << x);
    }
    if (cl == cr) {
        ans |= b;
        return;
    }
    dfs(b, cl, md, nx);
    dfs(b, md + 1, cr, nx + 1);
}
#undef md
#undef nx

int main() {
    cin >> n >> q;
    for (int i = 1; i <= q; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        ins(l, r, x, 1, n);
    }
    bitset<N> start;
    start[0] = true;
    dfs(start, 1, n);
    int k = 0;
    for (int i = 1; i <= n; ++i) k += ans[i];
    cout << k << "\n";
    for (int i = 1; i <= n; ++i)
        if (ans[i]) cout << i << " ";
    return 0;
}
