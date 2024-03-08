from itertools import *
from copy import *

def solve():
    n, g = map(int, input().split())
    edge = []
    g = [[] for _ in range(n)]
    for i in range(n-1):
        u, v, w = map(int, input().split())
        edge.append([u-1, v-1, w]);
        g[u-1].append([w, v-1])
        g[v-1].append([w, u-1])

    stickers = [[] for _ in range(n)]
    for i in range(n):
        stickers[i] = list(map(int, input().split()))

    def solve1():
        order = None

        for p in permutations(range(n-1)):
            skers = deepcopy(stickers)
            for i in range(n-1):
                u, v, w = edge[p[i]]
                if skers[u][-1]+skers[v][-1] < w:
                    break
                skers[u].pop()
                skers[v].pop()
            else:
                order = p

        if order == None:
            print("No")
        else:
            print("Yes")
            print(*map(lambda x: x+1, order))
    def solve2():
        solve2in

    if g <= 1: solve1()


        

solve()

