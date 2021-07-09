class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        nums.sort()
        res = 0
        for i in range(0, len(nums) - 1):
            res = max(res, nums[i + 1] - nums[i])
        return res