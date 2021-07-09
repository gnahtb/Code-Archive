class Solution:
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:
        slots1.sort()
        slots2.sort()
        
        def f(lista, listb):
            for l, r in lista:
                if r - l < duration:
                    continue
                lf = 0
                rg = len(listb) - 1
                po = -1
                while lf <= rg:
                    md = (lf + rg) // 2
                    if listb[md][0] <= l:
                        po = md
                        lf = md + 1
                    else:
                        rg = md - 1
                if po >= 0 and min(listb[po][1], r) - l >= duration:
                    return [l, l + duration]
                lf = 0
                rg = len(listb) - 1
                po = -1
                while lf <= rg:
                    md = (lf + rg) // 2
                    if listb[md][0] <= r - duration:
                        po = md
                        lf = md + 1
                    else:
                        rg = md - 1
                if po >= 0 and listb[po][1] >= r:
                    return [r - duration, r]
            return []
        
        res1 = f(slots1, slots2)
        res2 = f(slots2, slots1)
        if res1 == []:
            if res2 == []:
                return []
            else:
                return res2
        else:
            if res2 == []:
                return res1
            else:
                return min(res1, res2)