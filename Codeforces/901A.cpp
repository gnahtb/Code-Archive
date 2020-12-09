#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxH = 1E5 + 5;

int h, a[maxH];
bool flag = false;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> h;
    for (int i = 0; i <= h; ++i) cin >> a[i];
    for (int i = 1; i <= h; ++i)
        if (a[i] > 1 && a[i + 1] > 1) flag = true;
    if (!flag)
    {
        cout << "perfect";
        return 0;
    }
    cout << "ambiguous\n";
    flag = false;
    int sum = 0;
    for (int i = 0; i <= h; ++i)
    {
        for (int j = 1; j <= a[i]; ++j) cout << sum << " ";
        sum += a[i];
    }
    cout << "\n";
    sum = 0;
    for (int i = 0; i <= h; ++i)
    {
        int tmp = 0;
        if (a[i] > 1 && a[i - 1] > 1 && !flag)
        {
            cout << sum << " " << sum - 1 << " ";
            a[i] -= 2;
            tmp = 2;
            flag = true;
        }
        for (int j = 1; j <= a[i]; ++j) cout << sum << " ";
        sum += a[i] + tmp;
    }
    return 0;
}
