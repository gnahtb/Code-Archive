#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, d;
        cin >> n >> d;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a, a + n);
        string ans = "YES";
        for (int i = 0; i < n; ++i)
            if (a[i] > d) {
                if (a[0] + a[1] > d) {
                    ans = "NO";
                    break;
                }
            }
        cout << ans << "\n";
    }
    return 0;
}