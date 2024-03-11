import sys
sys.setrecursionlimit(10**9)

def solve():
    n, m = map(int, input().split())
    a = [input() for _ in range(n)]
    cost = [list(map(int, input().split())) for _ in range(n)]

    to = [[()]*m for _ in range(n)]
    vis = [[0]*m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if a[i][j] == "<":
                to[i][j] = (i, j+1)
            if a[i][j] == ">":
                to[i][j] = (i, j-1)
            if a[i][j] == "^":
                to[i][j] = (i+1, j)
            if a[i][j] == "v":
                to[i][j] = (i-1, j)
                

    sr = -1
    sc = -1
    for i in range(n):
        for j in range(m):
            if a[i][j] == ".":
                sr = i
                sc = j

    def in_grid(r, c):
        return 0 <= r < n and 0 <= c < m

    def dfs(r, c):
        res = 0
        vis[r][c] = 1

        for dr in [-1, 0, 1]:
            for dc in [-1, 0, 1]:
                if abs(dr)+abs(dc) == 1:
                    nr = r+dr
                    nc = c+dc
                    nnr = nr+dr
                    nnc = nc+dc
                    if not in_grid(nr, nc) or not in_grid(nnr, nnc):
                        continue
                    if to[nr][nc] == (nnr, nnc) and not vis[nnr][nnc]:
                        res += max(0, cost[nnr][nnc] + dfs(nnr, nnc))

        return res


    print(dfs(sr, sc))


solve()


