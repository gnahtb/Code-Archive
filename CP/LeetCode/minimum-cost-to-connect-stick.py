import heapq

class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        pq = []
        res = 0
        for i in sticks:
            heapq.heappush(pq, i)
        while len(pq) > 1:
            x = heapq.heappop(pq)
            y = heapq.heappop(pq)
            heapq.heappush(pq, x + y)
            res += x + y
        return res