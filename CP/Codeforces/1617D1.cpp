#include <bits/stdc++.h>

using namespace std;

int test;

int ask(int a, int b, int c) {
    cout << "? " << a << " " << b << " " << c << endl;
    cout.flush();
    int t;
    cin >> t;
    if (t < 0) exit(0);
    return t;
}

int main() {
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        int last_response = 2;
        int x = 0;
        for (int i = 1; i + 2 <= n; ++i) {
            int t = ask(i, i + 1, i + 2);
            if ((last_response ^ t) == 1) {
                if (last_response == 0) x = -i;
                else x = i;
                break;
            }
            last_response = t;
        }
        if (x == 0) {
            if (last_response == 0) {
                cout << "! " << (n / 3) << " ";
                for (int i = 3; i <= n; i += 3)
                    if (i % 3 == 0) cout << i << " ";
                cout << endl;
                cout.flush();
            } else {
                cout << "! " << (n / 3 * 2) << endl;
                for (int i = 1; i <= n; ++i)
                    if (i % 3 != 0) cout << i << " ";
                cout << endl;
                cout.flush();
            }
            cout.flush();
        } else {
            vector<int> ans;
            ans.clear();
            if (x > 0) ans.push_back(x + 2);
            else {
                x = -x;
                ans.push_back(x - 1);
            }
            for (int i = 1; i <= n; ++i)
                if (i != x + 2 && i != x - 1) {
                    int t = ask(x + 2, x - 1, i);
                    if (t == 0) ans.push_back(i);
                }
            cout << "! " << ans.size() << " ";
            for (int i : ans) cout << i << " ";
            cout << endl;
            cout.flush();
        }
    }
    return 0;
}