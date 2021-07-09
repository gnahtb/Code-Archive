import heapq

class MaxHeapObj(object):
    def __init__(self, val): self.val = val
    def __lt__(self, other): return self.val > other.val
    def __eq__(self, other): return self.val == other.val
    def __str__(self): return str(self.val)

class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        l = 1
        r = 1000000000
        ans = 1000000000
        while l <= r:
            m = (l + r) // 2
            needed_operations = 0
            for i in nums:
                parts = i // m
                if i % m > 0:
                    parts += 1
                needed_operations += parts - 1
            if needed_operations <= maxOperations:
                ans = m
                r = m - 1;
            else:
                l = m + 1
        return ans
