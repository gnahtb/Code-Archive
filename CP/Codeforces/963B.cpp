#include <bits/stdc++.h>

using namespace std;

#define odd(a) ((a) & 1)

const int maxN = 2E5 + 5;

int n;
vector<int> a[maxN], x;
stack<int> s, t;

int DFS(int u, int p)
{
    int d = p ? 1 : 0;
    s.push(u);
    for (int v: a[u]) if (v != p) d += DFS(v, u);
    if (odd(d)) return 1;
    while (t.empty() || t.top() != u) t.push(s.top()), s.pop();
    while (!t.empty()) x.push_back(t.top()), t.pop();
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int p;
        scanf("%d", &p);
        if (p) a[i].push_back(p), a[p].push_back(i);
    }
    if (!DFS(1, 0))
    {
        printf("YES\n");
        for (int i: x) printf("%d\n", i);
    }
    else printf("NO\n");
    return 0;
}
