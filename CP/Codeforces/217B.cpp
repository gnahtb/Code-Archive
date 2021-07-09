#include <bits/stdc++.h>

using namespace std;

int n, r, t = INT_MAX, x = -1;

void calc(int a, int b, int &c, int &d)
{
    while (a % b)
    {
        c += a / b; d += a / b - 1;
        int t = a % b; a = b; b = t;
    }
    if (b > 1) c = d = -1;
    else c += a / b - 1, d += a / b - 2;
}

void trace(int a, int b)
{
    vector<int> v;
    while (a % b)
    {
        v.push_back(a / b);
        int t = a % b; a = b; b = t;
    }
    v.push_back(a / b - 1);
    reverse(v.begin(), v.end());
    printf("T");
    char cur = 'B';
    for (int i: v)
    {
        for (int j = 0; j < i; ++j) printf("%c", cur);
        cur = cur == 'T' ? 'B' : 'T';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%d", &n, &r);
    if (n == 1 && r == 1) { printf("0\nT"); return 0; }
    for (int i = 1; i < r; ++i)
    {
        int p = 1, q = 0;
        calc(r, i, p, q);
        if (p == n && q < t) t = q, x = i;
    }
    if (x < 0) { printf("IMPOSSIBLE\n"); return 0; }
    printf("%d\n", t);
    trace(r, x);
    return 0;
}
