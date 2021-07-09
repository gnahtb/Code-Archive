class Solution:
    def minOperations(self, s: str) -> int:
        def operations(s: str, a):
            ret = 0
            flag = 0
            for i in s:
                if i != a[flag]:
                    ret = ret + 1
                flag = (flag + 1) % 2
            return ret
        
        return min(operations(s, ["0", "1"]), operations(s, ["1", "0"]))
