class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        candiesSum = list()
        for i in candiesCount:
            current = 0
            if len(candiesSum) > 0:
                current = candiesSum[-1]
            candiesSum.append(current + i)
        answer = list()
        for favType, favDay, dailyCap in queries:
            total_candies = candiesSum[favType]
            total_candies1 = 0 if favType == 0 else candiesSum[favType - 1]
            if total_candies1 >= dailyCap * (favDay + 1):
                answer.append(False)
            else:
                if total_candies >= favDay + 1:
                    answer.append(True)
                else:
                    answer.append(False)
        return answer