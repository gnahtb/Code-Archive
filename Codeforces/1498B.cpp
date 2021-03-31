#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int test, n, w, a[N];
multiset<long long> boxes;

int main() {
    cin >> test;
    while (test--) {
        cin >> n >> w;
        for (int i = 0; i < n; ++i) cin >> a[i];
        boxes.clear();
        sort(a, a + n, greater<int>());
        for (int i = 0; i < n; ++i) {
            set<long long>::iterator it = boxes.lower_bound(a[i]);
            if (it == boxes.end()) {
                boxes.insert(w - a[i]);
            } else {
                long long tmp = *it;
                boxes.erase(it);
                boxes.insert(tmp - a[i]);
            }
        }
        cout << boxes.size() << "\n";
    }
    return 0;
}