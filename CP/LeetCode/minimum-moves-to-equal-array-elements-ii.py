class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        med = nums[len(nums) // 2]
        res = 0
        for i in nums:
            res += abs(i - med)
        return res