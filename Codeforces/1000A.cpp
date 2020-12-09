#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0;
vector<string> a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        a.push_back(s);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        if (binary_search(a.begin(), a.end(), s))
            a.erase(lower_bound(a.begin(), a.end(), s));
        else ++ans;
    }
    cout << ans << "\n";
    return 0;
}
