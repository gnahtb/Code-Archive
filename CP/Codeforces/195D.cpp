#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int n;
vector<pii> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int b, k, d;
        cin >> b >> k;
        if (b == 0) continue;
        d = __gcd(b, k); b /= d; k /= d;
        v.push_back({b, k});
    }
    sort(v.begin(), v.end());
    v.resize(distance(v.begin(), unique(v.begin(), v.end())));
    cout << v.size() << "\n";
    return 0;
}
