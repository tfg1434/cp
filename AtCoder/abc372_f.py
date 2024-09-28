n, m, k = map(int, input().split())
if m == 0:
    print(1)
    exit()
edges = []
s = set([0])
for i in range(m):
    x, y = map(lambda x: int(x) - 1, input().split())
    s.add(x)
    s.add(y)
    edges.append((x, y))

s = sorted(list(s))
d = {}
sz = len(s)
for i in range(sz):
    d[s[i]] = i
edge = [[] for i in range(sz)]
print(s)
for i in range(sz):
    edge[i].append(((i + 1) % sz, (s[(i + 1) % sz] - s[i]) % n))
for x, y in edges:
    edge[d[x]].append((d[y], 1))

mod = 998244353
dp = [[0] * sz for i in range(k+1)]
dp[0][0] = 1
ans = 0
for i in range(k):
    for v in range(sz):
        for to, w in edge[v]:
            if i+w <= k:
                dp[i+w][to] += dp[i][v]
                dp[i+w][to] %= mod
            #  if i + w >= k:
                #  ans += dp[i][v]
                #  ans %= mod
            #  else:
                #  dp[i + w][to] += dp[i][v]
                #  dp[i + w][to] %= mod

for i in range(k+1):
    for v in range(sz):
        print(i, v, dp[i][v])
        ans += dp[i][v]

print(ans)

