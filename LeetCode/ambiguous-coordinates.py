class Solution:
    def ambiguousCoordinates(self, s: str) -> List[str]:
        s = s[1:-1]
        ret = set()
        for i in range(1, len(s)):
            l = s[:i]
            r = s[i:]
            set_l = set()
            set_r = set()
            if l[0] != '0' or len(l) == 1:
                set_l.add(l)
            for j in range(1, len(l)):
                l1 = l[:j]
                l2 = l[j:]
                if (l2[-1] != '0') and (l1[0] != '0' or len(l1) == 1):
                    set_l.add(f'{l1}.{l2}')
            if r[0] != '0' or len(r) == 1:
                set_r.add(r)
            for j in range(1, len(r)):
                r1 = r[:j]
                r2 = r[j:]
                if (r2[-1] != '0') and (r1[0] != '0' or len(r1) == 1):
                    set_r.add(f'{r1}.{r2}')
            for i in set_l:
                for j in set_r:
                    ret.add(f'({i}, {j})')
        return list(ret)