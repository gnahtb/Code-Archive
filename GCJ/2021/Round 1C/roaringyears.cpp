#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;
using ll = long long;

int test;

ll s_toi(string s) {
    ll ret = 0;
    for (int i = 0; i < sz(s); ++i)
        (ret *= 10) += s[i] - '0';
    return ret;
}

ll is_roaring(string y) {
    for (int i = 1; i <= sz(y); ++i) {
        ll t1 = s_toi(y.substr(0, i));
        // int l1 = sz(y.substr(0, i));
        int j = i;
        bool flag = true;
        while (j < sz(y)) {
            int l2 = sz(to_string(t1 + 1));
            string t2 = y.substr(j, l2);
            ll st2 = s_toi(t2);
            if (st2 == t1 + 1) {
                j += l2;
                ++t1;
            } else {
                flag = false;
                break;
            }
        }
        if (flag) return t1;
    }
    return -1;
}

bool is_roaring1(string y) {
    for (int i = 1; i < sz(y); ++i) {
        int t1 = s_toi(y.substr(0, i));
        int l1 = sz(y.substr(0, i));
        int j = i;
        bool flag = true;
        while (j < sz(y)) {
            int l2 = sz(to_string(t1 + 1));
            string t2 = y.substr(j, l2);
            int st2 = s_toi(t2);
            if (st2 == t1 + 1) {
                j += l2;
                ++t1;
            } else {
                flag = false;
                break;
            }
        }
        if (flag) return true;
    }
    return false;
}

string trau(ll y) {
    ++y;
    while (!is_roaring1(to_string(y))) ++y;
    return to_string(y);
}

int main() {
    srand(time(nullptr));
    freopen("inp.txt", "r", stdin);
    cin >> test;
    // int test = 10000;
    for (int itest = 1; itest <= test; ++itest) {
        // ll y = rand() % 1000000 + 1;
        ll y;
        cin >> y;

        string a1 = trau(y);
        string ys = to_string(y);

        string ans = ys + to_string(y + 1);

        for (int curt = 1; curt < 10; ++curt) {
            string tmp1 = "";
            int cur1 = curt - 1;
            while (sz(tmp1) < 2 || sz(tmp1) < sz(ys) || (sz(tmp1) == sz(ys) && tmp1 <= ys)) tmp1 += to_string(++cur1);
            if (sz(ans) > sz(tmp1)) ans = tmp1;
            else if (sz(ans) == sz(tmp1) && ans > tmp1) ans = tmp1;
        }
        
        for (int i = 1; i < sz(ys); ++i) {
            ll cur = is_roaring(ys.substr(0, i));
            if (cur > 0) {
                string tmp = ys.substr(i, sz(ys));
                string t1 = to_string(++cur);
                if (t1 > tmp) {
                    while (sz(t1) < sz(tmp)) t1 += to_string(++cur);
                } else {
                    while (sz(t1) <= sz(tmp)) t1 += to_string(++cur);
                }
                t1 = ys.substr(0, i) + t1;
                if (sz(t1) < sz(ans)) ans = t1;
                else if (sz(t1) == sz(ans) && t1 < ans) ans = t1;
            }
        }

        for (int i = 1; i < sz(ys); ++i) {
            ll cur = s_toi(ys.substr(0, i));
            string tmp = "";
            while (sz(tmp) < sz(ys)) tmp += to_string(cur++);
            bool flag = false;
            if (sz(tmp) > sz(ys)) flag = true;
            else if (sz(tmp) == sz(ys) && tmp > ys) flag = true;
            if (!flag) continue;
            if (sz(tmp) < sz(ans)) ans = tmp;
            else if (sz(tmp) == sz(ans) && tmp < ans) ans = tmp;
        }

        for (int i = 1; i < sz(ys); ++i) {
            ll cur = s_toi(ys.substr(0, i));
            string tmp = "";
            while (sz(tmp) < sz(ys)) tmp += to_string(++cur);
            if (sz(tmp) == sz(ys) && tmp <= ys) tmp += to_string(++cur);
            if (sz(tmp) < sz(ans)) ans = tmp;
            else if (sz(tmp) == sz(ans) && tmp < ans) ans = tmp;
        }

        cout << "Case #" << itest << ": " << y << " " << a1 << " " << ans << endl;
        if (a1 != ans) {
            break;
        }
    }
    return 0;
}