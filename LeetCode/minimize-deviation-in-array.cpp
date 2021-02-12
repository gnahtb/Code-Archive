#include <bits/stdc++.h>

#define sz(a) (int)a.size()
#define pii pair<int, int>

using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> values;
        vector<deque<int>> adj;
        adj.clear();
        adj.resize(sz(nums));
        values.clear();
        for (int i = 0; i < sz(nums); ++i) {
            values.insert(nums[i]);
            adj[i].push_back(nums[i]);
            if (nums[i] % 2 != 0) {
                values.insert(nums[i] * 2);
                adj[i].push_back(nums[i] * 2);
            }
            while (nums[i] % 2 == 0) {
                nums[i] /= 2;
                adj[i].push_front(nums[i]);
                values.insert(nums[i]);
            }
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq; // queue min
        priority_queue<int> pq1; // queue max
        for (int i = 0; i < sz(nums); ++i) {
            pq.emplace(adj[i].front(), i);
            pq1.push(adj[i].front());
        }
        // for (deque<int> i : adj) {
        //     for (int j : i) cout << j << " ";
        //     cout << "\n";
        // }
        // for (int i : values) cout << i << " ";
        int min_dif = INT_MAX;
        // cout << min_dif << "\n";
        for (int i : values) {
            // cout << i << "clgt\n";
            while (pq.top().first < i) {
                int idx = pq.top().second;
                // cout << idx << "\n";
                pq.pop();
                if (!adj[idx].empty()) adj[idx].pop_front();
                if (adj[idx].empty()) {
                    return min_dif;
                }
                pq.emplace(adj[idx].front(), idx);
                // cout << adj[idx].front() << "push\n";
                pq1.push(adj[idx].front());
                // cout << "ok1\n";
            }
            min_dif = min(min_dif, pq1.top() - pq.top().first);
        }
        return min_dif;
    }
};