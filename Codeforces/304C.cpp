#include <cstdio>
#include <iostream>

using namespace std;

int n, a[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n % 2 == 0)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        int x = i;
        if (x % 2 != 0) x += n;
        a[i] = x/2;
    }
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; ++i) cout << i << " ";
    return 0;
}
