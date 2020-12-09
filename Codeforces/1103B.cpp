#include <bits/stdc++.h>

using namespace std;

// 1 -> x >= y
// 0 -> x < y
inline bool ask(int x, int y) {
    // printf("? %d %d\n", x, y);
    cout << "? " << x << " " << y << "\n";
    cout.flush();
    char res;
    cin >> res;
    return res == 'x';
}

#define pw2(a) (1 << (a))
int solve() {
    int i = 0, ans = 0;
    bool flag = false;
    for (; i < 30; ++i)
        if (!ask(pw2(i + 1), pw2(i))) {
            flag = true;
            break;
        }
    if (!flag) return 1;
    // if (ask(pw2(i + 1), pw2(i + 2)) && ask(pw2(i + 2), pw2(i + 1)))
    //     return pw2(i + 1);
    ans = pw2(i);
    // pre = ask(ans + pw2(j), ans + pw2(j + 1));
    // bool pre = true;
    for (int j = i - 1; j >= 0; --j) {
        bool tmp = ask(ans + pw2(j), ans + pw2(j + 1));
        if (tmp) {
            ans += pw2(j);
            // pre = true;
            // continue;
        }
        // pre = tmp;
    }
    // return ans;
    if (ask(ans + 1, ans + ans + 2)) return ans + 1;
    return ans + (ans & -ans);
}

int main() {
    ios::sync_with_stdio(false);
    string t;
    while (true) {
        cin >> t;
        if (t == "mistake" || t == "end") break;
        int sol = solve();
        cout << "! " << sol << "\n";
        cout.flush();
    }
    return 0;
}
