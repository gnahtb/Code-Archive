#include <bits/stdc++.h>

using namespace std;

const int maxN = 1E5 + 5;

int n, s, f, a[maxN], tmp = 0, cur = 0, ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i % n]);
    scanf("%d%d", &s, &f);
    for (int i = 1; i < n; ++i)
    {
        int L = (s - i + n) % n, R = (f - i + n) % n;
        tmp += a[L] - a[R];
        if (tmp > cur) cur = tmp, ans = i;
    }
    printf("%d\n", ans + 1);
    return 0;
}
