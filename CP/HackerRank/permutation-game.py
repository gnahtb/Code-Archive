t = int(input())

def get_bit(m, i):
  return (m >> i) & 1

while t > 0:
  n = int(input())
  f = [0 for i in range(1 << n)]
  arr = list(map(int, input().split()))
  for m in range(1, 1 << n):
    prev = -1
    flag = True
    for i in range(n):
      if not get_bit(m, i):
        continue
      if prev >= 0 and arr[prev] > arr[i]:
        flag = False
        break
      else:
        prev = i
    if flag:
      continue
    for i in range(n):
      if get_bit(m, i):
        f[m] = f[m] or (f[m ^ (1 << i)] ^ 1)
  print("Alice" if f[(1 << n) - 1] else "Bob")
  t = t - 1