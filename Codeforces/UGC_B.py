from heapq import *

def solve():
    n, m, k, s, t = map(int, input().split())
    s -= 1
    t -= 1

    g = [[] for _ in range(n)]
    for i in range(m+k):
        u, v, l = map(int, input().split())
        u -= 1
        v -= 1
        if i >= m:
            l *= -1

        g[u].append((l, v))

    q = []
    dist = [[float('inf')]*2 for _ in range(n)]
    # dist, u, 0/1 traveled extra road
    heappush(q, (0, s, 0))
    dist[s][0] = 0

    while q:
        d, u, extra = heappop(q)
        if d != dist[u][extra]:
            continue

        for l, v in g[u]:
            if l < 0 and extra:
                continue
            if d+abs(l) < dist[v][extra or l < 0]:
                dist[v][extra or l < 0] = d+abs(l)
                heappush(q, (d+abs(l), v, extra or l < 0))
    

    print(min(dist[t]))



solve()
