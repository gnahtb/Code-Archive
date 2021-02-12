class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        n = len(events)
        for i in range(n):
            events[i] = [events[i][1], events[i][0], events[i][2]]
        events.sort()
        # print(events)
        f = [0] * (n + 1)
        ans = 0
        for i in range(k):
            g = [0] * (n + 1)
            for j in range(1, n + 1):
                l = 0
                r = j - 2
                j1 = -1
                while l <= r:
                    m = (l + r) // 2
                    if events[m][0] < events[j - 1][1]:
                        j1 = m
                        l = m + 1
                    else:
                        r = m - 1
                g[j] = max(g[j - 1], max(f[j], f[j1 + 1] + events[j - 1][2]))
                ans = max(ans, g[j])
            f = g
            # print(f)
        return f[n]