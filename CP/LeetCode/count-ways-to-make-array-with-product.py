MOD = 1000000007
N = 21000

class Solution:
    def binPow(self, x, y):
        if y == 0:
            return 1
        ret = self.binPow(x, y // 2)
        ret = ret * ret % MOD
        if y % 2 != 0:
            ret = ret * x % MOD
        return ret
    
    def waysToFillArray(self, queries: List[List[int]]) -> List[int]:
        answers = []
        
        fact = [1]
        for i in range(1, N + 1):
            fact.append(fact[i - 1] * i % MOD)
        inv_fact = [0] * (N + 1)
        inv_fact[N] = self.binPow(fact[N], MOD - 2)
        for i in range(N, 0, -1):
            inv_fact[i - 1] = inv_fact[i] * i % MOD
        
        def nCr(n, r):
            return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD
        
        prime_factor = [i for i in range(N + 1)]
        for i in range(2, N + 1):
            if prime_factor[i] != i:
                continue
            j = i * i
            while j <= N:
                prime_factor[j] = i
                j += i
        
        for n, k in queries:
            factor_powers = []
            while k > 1:
                factor = prime_factor[k]
                power = 0
                while k % factor == 0:
                    k = k // factor
                    power += 1
                factor_powers.append(power)
            answer = 1
            for i in factor_powers:
                answer = answer * nCr(n + i - 1, n - 1) % MOD
            answers.append(answer)

        return answers