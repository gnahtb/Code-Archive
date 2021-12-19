#include <bits/stdc++.h>

using namespace std;

int test;
map<tuple<int, int, int>, int> answers;

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
        answers.clear();
        tuple<int, int, int> t0, t1;
        for (int i = 1; i <= n; i += 3) {
            int t = ask(i, i + 1, i + 2);
            auto tt = make_tuple(i, i + 1, i + 2);
            answers[tt] = t;
            if (t == 0) t0 = tt;
            else t1 = tt;
        }
        set<int> ans;
        ans.clear();
        int a0 = answers[t0];
        int a1 = ask(get<1>(t0), get<2>(t0), get<0>(t1));
        int a2 = ask(get<2>(t0), get<0>(t1), get<1>(t1));
        int a3 = answers[t1];
        int aa, bb;
        if (a0 == 0 && a1 == 1) {
            ans.insert(get<0>(t0));
            aa = get<0>(t0);
            bb = get<0>(t1);
        }
        if (a1 == 0 && a2 == 1) {
            ans.insert(get<1>(t0));
            aa = get<1>(t0);
            bb = get<1>(t1);
        }
        if (a2 == 0 && a3 == 1) {
            ans.insert(get<2>(t0));
            aa = get<2>(t0);
            bb = get<2>(t1);
        }
        if (a0 == 1 && a1 == 0) {
            ans.insert(get<0>(t1));
            bb = get<0>(t0);
            aa = get<0>(t1);
        }
        if (a1 == 1 && a2 == 0) {
            ans.insert(get<1>(t1));
            bb = get<1>(t0);
            aa = get<1>(t1);
        }
        if (a2 == 1 && a3 == 0) {
            ans.insert(get<2>(t1));
            bb = get<2>(t0);
            aa = get<2>(t1);
        }
        if (ans.find(get<0>(t0)) == ans.end() && get<0>(t0) != aa && get<0>(t0) != bb && ask(aa, bb, get<0>(t0)) == 0) ans.insert(get<0>(t0));
        if (ans.find(get<1>(t0)) == ans.end() && get<1>(t0) != aa && get<1>(t0) != bb && ask(aa, bb, get<1>(t0)) == 0) ans.insert(get<1>(t0));
        if (ans.find(get<2>(t0)) == ans.end() && get<2>(t0) != aa && get<2>(t0) != bb && ask(aa, bb, get<2>(t0)) == 0) ans.insert(get<2>(t0));
        if (ans.find(get<0>(t1)) == ans.end() && get<0>(t1) != aa && get<0>(t1) != bb && ask(aa, bb, get<0>(t1)) == 0) ans.insert(get<0>(t1));
        if (ans.find(get<1>(t1)) == ans.end() && get<1>(t1) != aa && get<1>(t1) != bb && ask(aa, bb, get<1>(t1)) == 0) ans.insert(get<1>(t1));
        if (ans.find(get<2>(t1)) == ans.end() && get<2>(t1) != aa && get<2>(t1) != bb && ask(aa, bb, get<2>(t1)) == 0) ans.insert(get<2>(t1));
        for (pair<tuple<int, int, int>, int> i: answers) {
            if (i.first == t0 || i.first == t1) continue;
            if (i.second == 0) {
                int t = ask(get<0>(i.first), get<1>(i.first), bb);
                if (t == 0) {
                    ans.insert(get<0>(i.first));
                    ans.insert(get<1>(i.first));
                    t = ask(aa, bb, get<2>(i.first));
                    if (t == 0) ans.insert(get<2>(i.first));
                } else {
                    ans.insert(get<2>(i.first));
                    t = ask(aa, bb, get<0>(i.first));
                    if (t == 0) ans.insert(get<0>(i.first));
                    else ans.insert(get<1>(i.first));
                }
            } else {
                int t = ask(get<0>(i.first), get<1>(i.first), aa);
                if (t == 0) {
                    t = ask(aa, bb, get<0>(i.first));
                    if (t == 0) ans.insert(get<0>(i.first));
                    else ans.insert(get<1>(i.first));
                } else {
                    t = ask(aa, bb, get<2>(i.first));
                    if (t == 0) ans.insert(get<2>(i.first));
                }
            }
        }
        cout << "! " << ans.size() << " ";
        for (int i : ans) cout << i << " ";
        cout << endl;
        cout.flush();
    }
    return 0;
}