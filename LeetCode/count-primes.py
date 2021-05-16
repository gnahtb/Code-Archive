class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 3:
            return 0
        is_prime = [True] * n
        i = 2
        while i * i < n:
            if is_prime[i]:
                j = i * i
                while j < n:
                    is_prime[j] = False
                    j += i
            i += 1
        ret = 0
        for i in range(2, n):
            if is_prime[i]:
                ret += 1
        return ret