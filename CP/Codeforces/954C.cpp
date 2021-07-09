#include <cstdio>
#include <iostream>

using namespace std;

const int maxN = 2E5 + 5;

int n, a[maxN], y = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    if (n == 1) { printf("YES\n1000000000 1\n");; return 0; }
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[i - 1]) { printf("NO\n");; return 0; }
        y = max(y, abs(a[i] - a[i - 1]));
    }
    if (y > 1)
    {
        for (int i = 1; i < n; ++i)
        {
            int t = abs(a[i] - a[i - 1]);
            if (t > 1 && t != y) { printf("NO\n"); return 0; }
        }
        for (int i = 1; i < n; ++i)
        {
            int t = abs(a[i] - a[i - 1]);
            int c1 = (a[i - 1] % y) ? a[i - 1] % y : y;
            int r1 = (a[i - 1] - c1) / y + 1;
            int c2 = (a[i] % y) ? a[i] % y : y;
            int r2 = (a[i] - c2) / y + 1;
            if (t == 1 && r1 != r2) { printf("NO\n"); return 0; }
            if (t == y && c1 != c2) { printf("NO\n"); return 0; }
        }
    }
    printf("YES\n1000000000 %d\n", y);
    return 0;
}
