import heapq

class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.append([100001, 100001])
        events.sort()
        pq = []
        can_attend = 0
        current_day = 1
        for start, end in events:
            while len(pq) > 0 and current_day < start:
                current_event = heapq.heappop(pq)
                if current_event >= current_day:
                    can_attend += 1
                    current_day += 1
            heapq.heappush(pq, end)
            current_day = max(current_day, start)
        return can_attend