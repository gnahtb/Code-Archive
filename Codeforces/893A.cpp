#include <cstdio>
#include <iostream>

using namespace std;

int n, p1 = 1, p2 = 2, p3 = 3;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        if (a == p3)
        {
            cout << "NO";
            return 0;
        }
        if (a == p1) swap(p2, p3);
        if (a == p2) swap(p1, p3);
    }
    cout << "YES";
    return 0;
}
