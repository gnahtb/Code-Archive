#include <bits/stdc++.h>

#define sz(a) (int)a.size()

using namespace std;

const int N = 1002;

string s;
int sum[N];
vector<vector<int>> ans;

int main() {
    cin >> s;
    while (true) {
        int cur = 0, pivot = -1;
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < sz(s); ++i) {
            sum[i + 1] = sum[i] + (s[i] == '(');
        }
        for (int i = 1; i <= sz(s); ++i) {
            int p1 = sum[i];
            int p2 = sz(s) - i - (sum[sz(s)] - sum[i]);
            if (min(p1, p2) > cur) {
                cur = min(p1, p2);
                pivot = i;
            }
        }
        if (cur == 0) break;
        vector<int> idx1;
        idx1.clear();
        for (int i = 1; i <= pivot; ++i)
            if (s[i - 1] == '(' && sz(idx1) < cur) idx1.push_back(i);
        for (int i = sz(s), tmp = 0; i > pivot; --i)
            if (s[i - 1] == ')' && tmp < cur) idx1.push_back(i), ++tmp;
        sort(idx1.begin(), idx1.end());
        ans.push_back(idx1);
        reverse(idx1.begin(), idx1.end());
        for (int i : idx1) s.erase(i - 1, i);
    }
    cout << sz(ans) << "\n";
    for (vector<int>& vec : ans) {
        cout << sz(vec) << "\n";
        for (int i : vec) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
