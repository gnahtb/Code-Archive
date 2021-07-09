#include <bits/stdc++.h>

using namespace std;

int n;
long long k;
map<int, int> cnt;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++cnt[a];
    }
    map<int, int>::iterator l = cnt.begin(), r = cnt.end();
    --r;
    while (k > 0 && l != r) {
        if (l->second < r->second) {
            map<int, int>::iterator lnx = l;
            ++lnx;
            int dist = lnx->first - l->first;
            int tmp = min(k / l->second, 1LL * dist);
            k -= 1LL * l->second * tmp;
            if (tmp > 0) {
                cnt[l->first + tmp] += l->second;
                ++l;
            } else break;
        } else {
            map<int, int>::iterator rnx = r;
            --rnx;
            int dist = r->first - rnx->first;
            int tmp = min(k / r->second, 1LL * dist);
            k -= 1LL * r->second * tmp;
            if (tmp > 0) {
                cnt[r->first - tmp] += r->second;
                --r;
            } else break;
        }
    }
    cout << (r->first - l->first);
    return 0;
}