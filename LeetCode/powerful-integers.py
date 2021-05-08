class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        res = set()
        for i in range(20):
            for j in range(20):
                if pow(x, i) + pow(y, j) <= bound:
                    res.add(pow(x, i) + pow(y, j))
        return res