s = input()
if not "1" in s:
    print(-1)
    exit(0)
n = len(s)
s = s + s
nearest_one = [-1] * len(s)
for i in range(len(s)):
    if s[i] == "0":
        if i:
            nearest_one[i] = nearest_one[i - 1]
    else:
        nearest_one[i] = i
ans = 0
for i in range(n):
    ans = max(ans, i + n - 1 - nearest_one[i + n - 1])
print(ans)