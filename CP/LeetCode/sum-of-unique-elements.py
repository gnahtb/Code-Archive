class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        ans = 0
        freq = dict()
        for num in nums:
            if num not in freq:
                freq[num] = 0
            freq[num] += 1
        for key in freq:
            if freq[key] < 2:
                ans += key
        return ans