#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define fi first
#define se second
#define sqr(a) (a) * (a)

typedef pair<int, int> ii;

struct TNode { int l = 0, r = 0, v = 0; };

const int N = 200005;
const int M = 200005;

int n, m, p[N], id[N], qi[M], ans[M], fen[N];
ii q[M];
vector<int> u[N];

inline void update(int p) {
    for (int i = p; i <= n; i += i & -i) ++fen[i];
}

inline int sum(int p) {
    int ans = 0;
    for (int i = p; i; i -= i & -i) ans += fen[i];
    return ans;
}

void solve() {
    fill(fen, fen + N, 0);
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            u[max(id[i], id[j])].push_back(min(id[i], id[j]));
    for (int i = 1, j = 1; i <= n; ++i) {
        for (int k : u[i]) update(k);
        for (; j <= m && q[qi[j]].se == i; ++j)
            ans[qi[j]] = sum(i) - sum(q[qi[j]].fi - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &p[i]), id[p[i]] = i;
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &q[i].fi, &q[i].se), qi[i] = i;
    sort(qi + 1, qi + m + 1, [](int x, int y) { return q[x].se < q[y].se; });
    solve();
    for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
    return 0;
}
