import sys

from types import GeneratorType
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
    return wrappedfunc
sys.setrecursionlimit(1000000000)

def solve():
    n, m = map(int, input().split())
    g = [[] for i in range(n)]
    E = []
    for i in range(m):
        u, v, w = map(int, input().split())
        E.append((w, (u-1, v-1)))
        #  g[u-1].append((w, v-1))
        #  g[v-1].append((w, u-1))

    e = [-1]*n
    def find(u):
        if e[u] < 0:
            return u
        e[u] = find(e[u])
        return e[u]
    def unite(u, v):
        if (u:=find(u)) != (v:=find(v)):
            if e[u] > e[v]:
                u,v = v,u
            e[u] += e[v];
            e[v] = u

    UV = ()
    mn_w = -1
    E.sort(reverse=True)
    for w, edge in E:
        u,v = edge

        if find(u) == find(v):
            mn_w = w
            UV = (u, v)
        else:
            unite(u, v)
            g[u].append(v)
            g[v].append(u)

    assert(mn_w != -1)

    sol = []
    @bootstrap
    def dfs(u, p):
        if u == UV[1]:
            sol.append(u)
            yield True

        for v in g[u]:
            if v==p:
                continue
            if (yield dfs(v, u)):
                sol.append(u)
                yield True
        yield False
    
    #  def dfs(u, p):
        #  if u == UV[1]:
            #  sol.append(u)
            #  return True

        #  for v in g[u]:
            #  if v==p:
                #  continue
            #  if dfs(v, u):
                #  sol.append(u)
                #  return True
        #  return False
    dfs(UV[0], UV[0])

    print(mn_w, len(sol))
    print(*list(x+1 for x in sol))

t = int(input())
for _ in range(t):
    solve()
