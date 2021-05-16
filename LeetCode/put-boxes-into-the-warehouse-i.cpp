#include <set>
#include <vector>

using namespace std;

#define sz(a) (int)a.size()

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        multiset<int, greater<int>> boxes_set;
        for (int i : boxes) boxes_set.insert(i);
        vector<int> v(sz(warehouse));
        v[0] = warehouse[0];
        for (int i = 1; i < sz(warehouse); ++i)
            v[i] = min(v[i - 1], warehouse[i]);
        int ret = 0;
        for (int i = sz(warehouse) - 1; i >= 0; --i) {
            auto it = boxes_set.lower_bound(v[i]);
            if (it != boxes_set.end()) {
                boxes_set.erase(it);
                ++ret;
            }
        }
        return ret;
    }
};