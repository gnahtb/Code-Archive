#include <bits/stdc++.h>

using namespace std;

#define odd(a) (a & 1)

const int maxN = 1E5 + 5;

int n, ans = 0;
vector<int> a[maxN];

int DFS(int u, int p)
{
    int cnt = 1;
    for (int v: a[u]) if (v != p)
    {
        int tmp = DFS(v, u);
        if (odd(tmp)) cnt += tmp;
        else ++ans;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    if (odd(n)) { printf("-1\n"); return 0; }
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].push_back(v); a[v].push_back(u);
    }
    DFS(1, 0);
    printf("%d\n", ans);
    return 0;
}
