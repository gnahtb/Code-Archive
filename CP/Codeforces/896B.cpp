#include <bits/stdc++.h>

using namespace std;

// [1, p] -> [1, n / 2]
// [p + 1, c] -> [n / 2 + 1, n]
int n, m, c, p;
vector<int> ans;

bool won() {
    for (int i = 1; i <= n; ++i)
        if (ans[i] < 0) return false;
    return true;
}

int main() {
    cin >> n >> m >> c;
    p = c / 2 + (n % 2) * (c % 2);
    ans.assign(n + 2, -1);
    while (m--) {
        int a;
        cin >> a;
        if (a <= p) {
            int x = -1;
            for (int i = 1; i <= n; ++i) {
                if (ans[i] < 0 || ans[i] > a) {
                    x = i;
                    break;
                }
            }
            ans[x] = a;
            cout << x << endl;
        } else {
            int x = -1;
            for (int i = n; i; --i) {
                if (ans[i] < 0 || ans[i] < a) {
                    x = i;
                    break;
                }
            }
            ans[x] = a;
            cout << x << endl;
        }
        if (won())
            return 0;
    }
    return 0;
}
