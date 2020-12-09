#include <bits/stdc++.h>

using namespace std;

int n;
char s[105];

int main()
{
    ios_base::sync_with_stdio(false);
    scanf("%d%s", &n, &s);
    for (int d = 2; d <= n; ++d)
    {
        if (n % d != 0) continue;
        int l = 0, r = d - 1;
        while (l < r) swap(s[l++], s[r--]);
    }
    printf("%s\n", s);
    return 0;
}
