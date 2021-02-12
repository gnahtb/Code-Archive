class Solution:
    def minimumLength(self, s: str) -> int:
        l = 0
        r = len(s) - 1
        while l < r and s[l] == s[r]:
            print(l, r)
            x = s[l]
            while l <= r and s[l] == x:
                l += 1
            while l <= r and s[r] == x:
                r -= 1
        return r - l + 1