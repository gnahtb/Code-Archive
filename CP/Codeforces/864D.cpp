#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define fill(a, b) memset(a, b, sizeof a);

int n, ans = 0, a[200005], c[200005];
bool flag[200005];

int main()
{
	cin >> n;
	fill(c, 0);
	fill(flag, true);
	for (int i = 1; i <= n; ++i) cin >> a[i], ++c[a[i]];
	int j = 1;
	for (int i = 1; i <= n; ++i)
        if (c[i] < 1)
            for (; j <= n; ++j)
                if (c[a[j]] > 1)
                    if (i > a[j] && flag[a[j]]) flag[a[j]] = false;
                    else
                    {
                        ++ans; --c[a[j]]; ++c[i];
                        a[j] = i;
                        ++j;
                        break;
                    }
    cout << ans << "\n";
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    return 0;
}
