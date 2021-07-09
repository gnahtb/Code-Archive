#include <bits/stdc++.h>

using namespace std;

string s, t;
bool chk = false;
int k, d[1000], d1[1000], cnt = 0;

int main() {
    ios::sync_with_stdio(false);
    cin >> s >> k;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '?') {
            d[t.size() - 1] = -1;
            ++cnt;
        } else if (s[i] == '*') {
            d[t.size() - 1] = -2;
            ++cnt;
            chk = true;
        } else t += s[i];
    }
    if (k < t.size() - cnt) {
        cout << "Impossible\n";
        return 0;
    }
    k -= t.size();
    if (k > 0 && !chk) {
        cout << "Impossible\n";
        return 0;
    }
    if (k < 0) {
        for (int i = 0; i < t.size(); ++i) {
            if (d[i] < 0 && abs(k) > 0) {
                d1[i] = k / abs(k);
                k -= d1[i];
            }
        }
    } else if (k > 0) {
        for (int i = 0; i < t.size(); ++i) {
            if (d[i] == -2) {
                d1[i] = k;
                break;
            }
        }
    }
    for (int i = 0; i < t.size(); ++i) {
        if (d[i] == -1) {
            if (d1[i] != -1) cout << t[i];
        } else if (d[i] == -2) {
            if (d1[i] == -1) continue;
            cout << t[i];
            for (int j = 0; j < d1[i]; ++j) cout << t[i];
        } else cout << t[i];
    }
    return 0;
}
