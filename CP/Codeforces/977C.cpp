#include <bits/stdc++.h>

using namespace std;

const int maxN = 2E5 + 5;

int n, k, a[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    a[n + 1] = INT_MAX;
    if (k == 0)
    {
        int tmp = a[1] - 1;
        if (tmp == 0) puts("-1");
        else printf("%d\n", tmp);
        return 0; 
    }
    if (a[k + 1] == a[k]) { puts("-1"); return 0; }
    printf("%d\n", a[k]);
    return 0;
}
