import heapq
import math
from typing import List

class Solution:
    def isPossible(self, target: List[int]) -> bool:
        
        def is_a(arr):
            for i in arr:
                if i != 1:
                    return False
            return True
        
        if len(target) == 1:
            return target[0] == 1
        elif len(target) == 2:
            return math.gcd(target[0], target[1]) == 1
        
        pq = []
        sum = 0
        for i, v in enumerate(target):
            heapq.heappush(pq, (-v, i))
            sum += v
        while not is_a(target):
            vmax, i = heapq.heappop(pq)
            vmax = -vmax
            sum1 = sum - vmax
            v1 = vmax - sum1
            if sum1 == 1:
                target
            target[i] = v1 % sum1
            print(target)
            sum = sum1 + v1
            if v1 < 1:
                return False
            heapq.heappush(pq, (-v1, i))
        return True