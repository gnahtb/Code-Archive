#include <bits/stdc++.h>

using namespace std;

#define sqr(a) (a) * (a)
#define sz(a) int(a.size())

struct TPoint { int x, y; };

const int maxN = 1E5 + 5;
const int lim = 1E6 + 5;

int n, a, ans = 0;
TPoint p[maxN];
vector<int> u[lim];
priority_queue<int, vector<int>> h;

template <class T>
void maximize(T &a, T b) { if (a < b) a = b; }

void solveByX()
{
    for (int i = 0; i < n; ++i) u[p[i].x].push_back(p[i].y);
    for (int s = 1; sqr(s) <= a; ++s)
    {
        int t = a / s;
        for (int v: u[s]) if (v <= t) h.push(v);
        while (!h.empty() && h.top() > t) h.pop();
        maximize(ans, sz(h));
    }
}

void solveByY()
{
    for (int i = 1; i <= 1E6; ++i) u[i].clear();
    while (!h.empty()) h.pop();
    for (int i = 0; i < n; ++i) u[p[i].y].push_back(p[i].x);
    for (int s = 1; sqr(s) <= a; ++s)
    {
        int t = a / s;
        for (int v: u[s]) if (v <= t) h.push(v);
        while (!h.empty() && h.top() > t) h.pop();
        maximize(ans, sz(h));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &a);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &p[i].x, &p[i].y);
    solveByX();
    solveByY();
    printf("%d\n", ans);
    return 0;
}