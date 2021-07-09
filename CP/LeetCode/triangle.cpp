#include <algorithm>
#include <iostream>

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> f[2];
        f[0].push_back(triangle[0][0]);
        for (size_t i = 1; i < triangle.size(); ++i) {
            f[i & 1].assign(triangle[i].size(), 1000000);
            for (size_t j = 0; j < triangle[i].size(); ++j) {
                if (j)
                    f[i & 1][j] = min(f[i & 1][j], f[(i - 1) & 1][j - 1]);
                if (j < triangle[i].size() - 1)
                    f[i & 1][j] = min(f[i & 1][j], f[(i - 1) & 1][j]);
                f[i & 1][j] += triangle[i][j];
            }
        }
        return *(std::min_element(f[(triangle.size() - 1) & 1].begin(), f[(triangle.size() - 1) & 1].end()));
    }
};