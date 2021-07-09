test = int(input())
for itest in range(test):
  n = int(input())
  intervals = []
  for i in range(n):
    a, b = map(int, input().split())
    intervals.append((b, -a))
  intervals.sort()
  p1 = 0
  p2 = 0
  res = 0
  for i in intervals:
    if -i[1] > p2:
      if -i[1] <= p1:
        p2 = p1
      p1 = i[0]
      res = res + 1
  print(res)