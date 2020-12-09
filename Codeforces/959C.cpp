#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;
    if (n < 6) cout << -1 << "\n";
    else
    {
        cout << "1 2\n1 3\n1 4\n";
        for (int i = 5; i <= n; ++i) cout << i <<  " 2\n";
    }
    for (int i = 2; i <= n; ++i) cout << i << " 1\n";
}
