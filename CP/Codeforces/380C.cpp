#include <bits/stdc++.h>

using namespace std;

struct TSegmentTreeNode { int f = 0, o = 0, c = 0; };

const int maxN = 1E6 + 5;

int n, m;
char s[maxN];
TSegmentTreeNode st[maxN * 4];

TSegmentTreeNode operator +(TSegmentTreeNode l, TSegmentTreeNode r)
{
    int t = min(l.o, r.c);
    return {l.f + r.f + t * 2, l.o + r.o - t, l.c + r.c - t};
}

void build(int i, int l, int r)
{
    if (l == r)
    {
        s[l - 1] == '(' ? st[i].o = 1 : st[i].c = 1;
        return;
    }
    build(i * 2, l, (l + r) / 2);
    build(i * 2 + 1, (l + r) / 2 + 1, r);
    st[i] = st[i * 2] + st[i * 2 + 1];
}

TSegmentTreeNode query(int i, int l, int r, int p, int q)
{
    if (l > q || r < p) return {0, 0, 0};
    if (p <= l && r <= q) return st[i];
    return query(i * 2, l, (l + r) / 2, p, q) + query(i * 2 + 1, (l + r) / 2 + 1, r, p, q);
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%s\n", &s);
    n = strlen(s);
    build(1, 1, n);
    scanf("%d", &m);
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(1, 1, n, l, r).f);
    }
    return 0;
}
