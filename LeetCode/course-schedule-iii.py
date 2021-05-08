import heapq
from typing import List

class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        # sort by the due day descendingly
        courses.sort(key=lambda x: x[1], reverse=True)
        pq = []
        ans = 0
        for i in range(len(courses)):
            t = courses[i][1] - (0 if i + 1 >= len(courses) else courses[i + 1][1])
            heapq.heappush(pq, courses[i][0])
            while t > 0 and len(pq) > 0:
                t1 = pq[0]
                heapq.heappop(pq)
                if t1 <= t:
                    t = t - t1
                    ans = ans + 1
                else:
                    heapq.heappush(pq, t1 - t)
                    t = 0
        return ans