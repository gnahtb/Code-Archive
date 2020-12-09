#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)a.size()

int n;
long long pa = 0, pb = 0;
vector<int> va, vb;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        va.push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        vb.push_back(a);
    }
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    while (sz(va) + sz(vb) > 0) {
        if (sz(vb) == 0) {
            pa += (long long)va.back();
            va.pop_back();
        } else {
            if (sz(va) == 0) vb.pop_back();
            else {
                if (vb.back() > va.back()) vb.pop_back();
                else {
                    pa += (long long)va.back();
                    va.pop_back();
                }
            }
        }
        // cout << pa << " " << pb << "\n";
        if (sz(va) + sz(vb) == 0) break;
        if (sz(va) == 0) {
            pb += (long long)vb.back();
            vb.pop_back();
        } else {
            if (sz(vb) == 0) va.pop_back();
            else {
                if (va.back() > vb.back()) va.pop_back();
                else {
                    pb += (long long)vb.back();
                    vb.pop_back();
                }
            }
        }
        // cout << pa << " " << pb << "\n";
    }
    cout << pa - pb << "\n";
    return 0;
}
