#include <cmath>
#include <iostream>

using namespace std;

#define sqr(a) (a) * (a)

const int maxN = 1005;

int n;
double r, x[maxN], ans[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> r;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i)
    {
        ans[i] = r;
        for (int j = 1; j < i; ++j)
            if (r + r >= abs(x[i] - x[j]))
                ans[i] = max(ans[i], ans[j] + sqrt(sqr(r + r) - sqr(x[i] - x[j])));
    }
    (cout << fixed).precision(10);
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
