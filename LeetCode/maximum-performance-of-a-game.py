import heapq

class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        idx = [i for i in range(n)]
        idx.sort(key=lambda x: efficiency[x], reverse=True)
        pq = []
        cursum = ans = 0
        for i in range(n):
            if len(pq) < k:
                heapq.heappush(pq, speed[idx[i]])
                cursum += speed[idx[i]]
            else:
                if pq[0] < speed[idx[i]] :
                    cursum -= heapq.heappop(pq)
                    heapq.heappush(pq, speed[idx[i]])
                    cursum += speed[idx[i]]
            ans = max(ans, cursum * efficiency[idx[i]])
        return ans % 1000000007