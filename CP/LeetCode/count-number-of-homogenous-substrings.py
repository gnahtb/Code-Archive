class Solution:
    def countHomogenous(self, s: str) -> int:
        MOD = 1000000007
        l = 0
        ans = 0
        while l < len(s):
            r = l + 1
            while r < len(s) and s[l] == s[r]:
                r += 1
            ans += (r - l) * (r - l + 1) // 2 % MOD
            ans %= MOD
            l = r
        return ans
