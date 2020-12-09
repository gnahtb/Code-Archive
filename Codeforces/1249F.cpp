#include <bits/stdc++.h>

using namespace std;

const int N = 202;
const int oo = 0x3f3f3f3f;

int n, k, w[N];
vector<int> adj[N];

int f[N][N], ans = -oo;

void Opt(int& x, int y) {
    if (x < y) x = y;
}

void DFS(int u, int p) {
    bool leaf = true;
    for (int v : adj[u])
        if (v != p) {
            DFS(v, u);
            leaf = false;
        }
    if (leaf) {
        f[u][0] = w[u];
        Opt(ans, w[u]);
        return;
    }
    f[u][0] = w[u];
    for (int v : adj[u]) if (v != p) {
        f[u][0] += max(0, f[v][k]);
    }
    for (int v : adj[u]) if (v != p) {
        for (int i = 0; i <= k + 1; ++i) {
            Opt(f[u][i + 1], f[v][i]);
            int tmp = f[v][i];
            for (int v1 : adj[u]) if (v1 != v && v1 != p) {
                tmp += max(0, f[v1][max(i, k - i - 1)]);
            }
            Opt(f[u][i + 1], tmp);
        }
    }
    for (int i = 0; i <= k + 1; ++i) Opt(ans, f[u][i]);
    for (int i = k; i >= 0; --i) {
        Opt(f[u][i], f[u][i + 1]);
    }
}

void Print() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k + 1; ++j) {
            printf("f[%d][%d] = %d\n", i, j, f[i][j]);
        }
        printf("\n");
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(f, -oo, sizeof(f));
    DFS(1, 0);
    // Print();
    printf("%d\n", ans);
    return 0;
}
