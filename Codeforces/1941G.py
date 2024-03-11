from collections import *
from heapq import *

def constant_factory(value):
    return lambda: value

def solve():
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]
    colours = []
    for _ in range(m):
        u, v, c = map(int, input().split())
        colours.append(c)
        u -= 1
        v -= 1
        g[u].append((c, v))
        g[v].append((c, u))

    s, t = map(int, input().split())
    s -= 1
    t -= 1
    if s == t:
        return print(0)

    dist = defaultdict(constant_factory(float('inf')))
    q = []
    dist[(s, -1)] = 0
    heappush(q, (0, (s, -1)))
    while q:
        d, more = heappop(q)
        if d != dist[more]:
            continue

        u, prv = more

        for c, v in g[u]:
            if d+(prv != c) < dist[(v, c)]:
                dist[(v, c)] = d+(prv != c)
                heappush(q, (dist[(v, c)], (v, c)))

    #  print(dist)
    ans = float('inf')
    for c in colours:
        ans = min(ans, dist[t, c])

    print(ans)


for _ in range(int(input())):
    solve()


