/*********************************************************************
Given a multiset of N integers. Consider all 2^N subsets sorted by 
their sum (the empty subset has sum 0). Print the first K subsets.

Trick to iterate fast through first K smallest subsets
Contributor: kuroni
----------------------------------------------------------------------
Assume that all integers are not negative and the multiset is sorted 
in ascending order. 
Consider each subset as a bitmask where 1 denotes an integer is chosen 
and 0 for not being chosen.
Initially the empty set has the smallest sum equal 0.
Create a heap that return the current smallest sum. For each step, we
take out the smallest sum S and push 2 values S - a[x] + a[x + 1] and 
S + a[x + 1] into the heap where x is the right-most chosen index.

In order to handle negative integers, we consider the empty subset has
the smallest sum equal sum of all negative integers. In that case, we 
can turn all negative integers into their opposite numbers.

Author: thang040602
*********************************************************************/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define long long long
#define fi first
#define se second

typedef pair<long, int> li;

const int N = 1E5 + 5;

int n, k;
long a[N], t = 0;
priority_queue<li, vector<li>, greater<li>> q;
vector<long> ans;

void solve() {
    q.push({t, 0});
    while (k--) {
        t = q.top().fi;
        int i = q.top().se;
        q.pop(); ans.push_back(t);
        if (i < n) {
            q.push({t + a[i + 1], i + 1});
            if (i) q.push({t - a[i] + a[i + 1], i + 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] < 0) t += a[i], a[i] *= -1;
    }
    sort(a + 1, a + n + 1);
    solve();
    for (long i: ans) cout << i << "\n";
}