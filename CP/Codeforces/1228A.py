import sys

l, r = map(int, input().split())
for i in range(l, r + 1, 1):
    s = str(i)
    chk = []
    for j in range(0, 10, 1): chk.append(0)
    for c in s: chk[int(c)] += 1
    flag = True
    for j in range(0, 10, 1):
        if (chk[j] > 1): flag = False
    if (flag):
        print(i)
        sys.exit(0)
print(-1)
