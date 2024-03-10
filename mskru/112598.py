from heapq import *

class Mx:
    #  I don't see a good way to do this, since we can't use
    #  None as a negative inf for everything in python 3
    def __init__(self):
        self.x = 0
        self.y = 0
        self.z = 0

    def ckmax(self, x):
        if x > self.x:
            if self.x > self.y:
                self.z = self.y
                self.y = self.x
            else:
                self.z = self.x

            self.x = x
        else:
            if x > self.y:
                self.z = self.y
                self.y = x
            else:
                self.z = max(self.z, x)

def unit_test():
    mx = Mx()
    mx.ckmax(3)
    mx.ckmax(3)
    mx.ckmax(3)
    mx.ckmax(4)
    mx.ckmax(2)
    assert(mx.x == 4)
    assert(mx.y == 3)
    assert(mx.z == 3)

def solve():
    n = int(input())
    g = [[] for _ in range(n)]
    for _ in range(n-1):
        u, v = map(int, input().split())
        g[u-1].append(v-1)
        g[v-1].append(u-1)

    ans = 0
    mxlvl = [Mx() for _ in range(n)]
    lvl = [0]*n
    def dfs(u, p):
        nonlocal ans

        if u != p:
            lvl[u] = lvl[p]+1
        mxlvl[u].ckmax(lvl[u])

        mx1lvls = Mx()
        mx1lvls.x = [] # hack
        mx1lvls.y = []
        mx1lvls.z = []
        lens = Mx()
        for v in g[u]:
            if v == p:
                continue
            dfs(v, u)
            
            mxlvl[u].ckmax(mxlvl[v].x+1)
            lens.ckmax(mxlvl[v].x+mxlvl[v].y)
            mx1lvls.ckmax([mxlvl[v].x, v])

        # Case 1
        ans = max(ans, lens.x*lens.y)

        # Case 2
        for v in g[u]:
            if v == p:
                continue
            inner = mxlvl[v].x+mxlvl[v].y

            if v != mx1lvls.x[1] and v != mx1lvls.y[1]:
                outer = mx1lvls.x[0]+mx1lvls.y[0]
            elif v == mx1lvls.x[1]:
                outer = mx1lvls.y[0]+mx1lvls.z[0]
            elif v == mx1lvls.y[1]:
                outer = mx1lvls.x[0]+mx1lvls.z[0]

            ans = max(ans, inner*(outer+2))

    dfs(0, 0)
    ps(ans)

unit_test()
solve()
