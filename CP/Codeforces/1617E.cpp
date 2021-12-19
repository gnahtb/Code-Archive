#include <bits/stdc++.h>

using namespace std;

struct mydata {
    tuple<int, int, int> ans;
    tuple<int, int> f1;

    mydata() {
        ans = make_tuple(0, 0, 0);
        f1 = make_tuple(0, 0);
    }

    mydata(tuple<int, int, int> _ans, tuple<int, int> _f1) {
        ans = _ans;
        f1 = _f1;
    }
};

int n;
set<int, greater<int>> pq;
map<int, mydata> f;
map<int, int> idx;

void init(int x, int y) {
    pq.insert(x);
    if (f.find(x) != f.end()) return;
    f[x] = mydata(make_tuple(y, x, x), make_tuple(y, x));
}

void print2(tuple<int, int> t2) {
    cout << get<0>(t2) << " " << get<1>(t2) << endl;
}

void print3(tuple<int, int, int> t3) {
    cout << get<0>(t3) << " " << get<1>(t3) << " " << get<2>(t3) << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        init(a, 0);
        idx[a] = i + 1;
    }
    while (!pq.empty()) {
        int u = *pq.begin();
        pq.erase(pq.begin());
        if (u == 0) break;
        // cout << u << endl;
        // print2(f[u].f1);
        // print3(f[u].ans);
        int t = __lg(u);
        int p = (1 << t) == u ? 0 : ((1 << (t + 1)) - u);
        init(p, -1);
        f[p].ans = max(f[p].ans, f[u].ans);
        // print3(f[p].ans);
        // print2(f[p].f1);
        if (get<0>(f[p].f1) >= 0 && get<0>(f[p].ans) < get<0>(f[p].f1) + get<0>(f[u].f1) + 1) {
            f[p].ans = make_tuple(get<0>(f[p].f1) + get<0>(f[u].f1) + 1, get<1>(f[p].f1), get<1>(f[u].f1));
            // print3(f[p].ans);
        }
        f[p].f1 = max(f[p].f1, make_tuple(get<0>(f[u].f1) + 1, get<1>(f[u].f1)));
        // print2(f[p].f1);
    }
    auto ans = f[0].ans;
    cout << idx[get<1>(ans)] << " " << idx[get<2>(ans)] << " " << get<0>(ans);
    return 0;
}