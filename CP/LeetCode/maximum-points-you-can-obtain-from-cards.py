from typing import List

class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        cursum = 0
        k = len(cardPoints) - k
        for i in range(k):
            cursum += cardPoints[i]
        summin = cursum
        for i in range(k, len(cardPoints)):
            cursum += cardPoints[i] - cardPoints[i - k]
            summin = min(summin, cursum)
        return sum(cardPoints) - summin