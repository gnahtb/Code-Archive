class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        def digitSum(x):
            ret = 0
            while x > 0:
                ret = ret + x % 10
                x = x // 10
            return ret
        
        freq = dict()
        ans = 0
        for i in range(lowLimit, highLimit + 1):
            digitsum = digitSum(i)
            if digitsum not in freq:
                freq[digitsum] = 0
            freq[digitsum] += 1
            ans = max(ans, freq[digitsum])
        return ans