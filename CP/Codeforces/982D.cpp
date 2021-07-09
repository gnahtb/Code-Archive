#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;

const int maxN = 1E5 + 5;

int n, a[maxN], lab[maxN], dep[maxN], len[maxN], k = 0;
vector<int> o;
priority_queue<ii, vector<ii>, greater<ii>> h;

int findSet(int u) { return lab[u] ? findSet(lab[u]) : u; }

void makeSet(int s1, int s2)
{
    if (dep[s1] < dep[s2]) swap(s1, s2);
    lab[s2] = s1;
    dep[s1] = max(dep[s1], dep[s2] + 1);
    len[s1] += len[s2];
}

void solve()
{
    fill(len + 1, len + n + 1, 1);
    int cur = 0, cnt = 0, lenMax = 0;
    for (int i: o)
    {
        int dif = 1;
        if (i > 1 && a[i - 1] <= a[i])
            makeSet(findSet(i - 1), i), --dif;
        if (i < n && a[i + 1] <= a[i])
            makeSet(findSet(i + 1), findSet(i)), --dif;
        int u = findSet(i);
        cnt += dif;
        lenMax = max(lenMax, len[u]);
        h.push({len[u], u});
        while (!h.empty() && h.top().fi != len[h.top().se]) h.pop();
        if (lenMax == h.top().fi && cur < cnt) cur = cnt, k = a[i] + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), o.push_back(i);
    sort(o.begin(), o.end(), [](int x, int y) { return a[x] < a[y]; });
    solve();
    printf("%d\n", k);
    return 0;
}
