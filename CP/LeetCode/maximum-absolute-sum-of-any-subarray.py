class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        n = len(nums)
        pref_sum = [0] * (n + 1)
        for i in range(n):
            pref_sum[i + 1] = pref_sum[i] + nums[i]
            # print(pref_sum[i + 1])
        sum_max = 0
        sum_min = 0
        ans = 0
        for i in range(1, n + 1):
            ans = max(ans, max(pref_sum[i] - sum_min, sum_max - pref_sum[i]))
            sum_max = max(sum_max, pref_sum[i])
            sum_min = min(sum_min, pref_sum[i])
        return ans