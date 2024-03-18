from queue import Queue

def solve():
    n = int(input())
     
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        u,v = [int(x) - 1 for x in input().split()]
        g[u].append(v)
        g[v].append(u)
     
    def furthest(u):
        G = [g[i][:] for i in range(n)]
        bfs = [u]
        for u in bfs:
            for v in G[u]:
                G[v].remove(u)
            bfs += G[u]
    a = furthest(0)
    b = furthest(a)

    


