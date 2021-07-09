import bisect

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) < 1:
            return [-1, -1]
        l = bisect.bisect_left(nums, target)
        if l >= len(nums) or l < 0 or nums[l] != target:
            return [-1, -1]
        r = bisect.bisect_right(nums, target)
        return [l, r - 1]