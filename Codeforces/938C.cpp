#include <bits/stdc++.h>

using namespace std;

#define sqr(a) (a) * (a)

int t;

void solve(int x)
{
    if (x == 0) { printf("1 1\n"); return; }
    for (int i = 1; sqr(i) <= x; i++) if (x % i == 0)
    {
        int c = i, d = x / i;
        if (((c + d) & 1) == 0)
        {
            int a = (c + d) >> 1, b = a - c;
            if (a >= b && b > 0)
            {
                int m = a / b;
                if (a / m == b) { printf("%d %d\n", a, m); return; }
            }
        }
    }
    printf("-1\n");
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int x;
        scanf("%d", &x);
        solve(x);
    }
    return 0;
}
