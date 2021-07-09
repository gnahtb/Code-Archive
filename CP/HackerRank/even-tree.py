n, m = map(int, input().split())
edges = set()
for i in range(m):
  u, v = map(int, input().split())
  u = u - 1
  v = v - 1
  edges.add((u, v))
  edges.add((v, u))


def dfs(u, p):
  is_leaf = False
  current = 1
  forest_size = 0
  for v in range(n):
    if v != p and (u, v) in edges:
      is_leaf = False
      temp = dfs(v, u)
      current = current + temp[1]
      forest_size = forest_size + temp[0]
  if is_leaf:
    return (0, 1)
  else:
    if current % 2 == 0:
      forest_size = forest_size + 1
      current = 0
    return (forest_size, current)


print(dfs(0, 0)[0] - 1)