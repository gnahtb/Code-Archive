class Solution:
    def superpalindromesInRange(self, left: str, right: str) -> int:
        
        def is_palin(x: str):
            for i in range(len(x) // 2):
                if x[i] != x[len(x) - i - 1]:
                    return False
            return True
        
        def f(x: int):
            ret = 0
            for i in range(1, 100000):
                x1 = int(str(i) + str(i)[::-1])
                if x1 * x1 < x and is_palin(str(x1 * x1)):
                    ret += 1
                x2 = int(str(i)[:-1] + str(i)[::-1])
                if x2 * x2 < x and is_palin(str(x2 * x2)):
                    ret += 1
                if x2 * x2 >= x:
                    break
            return ret
        
        return f(int(right) + 1) - f(int(left))