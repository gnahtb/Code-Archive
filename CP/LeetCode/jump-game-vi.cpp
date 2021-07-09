class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int> f;
        f.assign(nums.size(), INT_MIN);
        f[0] = nums[0];
        deque<int> dq;
        dq.clear();
        dq.push_back(0);
        for (int i = 1; i < (int)nums.size(); ++i) {
            while (!dq.empty() && i - k > dq.front()) dq.pop_front();
            f[i] = f[dq.front()] + nums[i];
            while (!dq.empty() && f[dq.back()] < f[i]) dq.pop_back();
            dq.push_back(i);
        }
        return f[nums.size() - 1];
    }
};