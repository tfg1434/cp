import sys
sys.setrecursionlimit(10000)
N = int(input())
edge = [[] for i in range(N)]
for i in range(N-1):
    U,V = map(int,input().split())
    edge[U-1].append(V-1)
    edge[V-1].append(U-1)
dp = [[] for i in range(N)]
mod = int(1e9+7)
def dfs(now):
    dp[now] = [[0]*3 for i in range(2)]
    dp[now][1][0] = dp[now][0][1] = 1
    for nex in edge[now]:
        if dp[nex]:
            continue
        dfs(nex)
        x = len(dp[now])-1
        y = len(dp[nex])-1
        cp = [[0]*3 for i in range(x+y+2)]
        for i in range(x+1):
            for j in range(y+1):
                cp[i+j][0] += dp[now][i][0]*dp[nex][j][0]
                cp[i+j][0] %= mod
                cp[i+j+1][0] += dp[now][i][0]*dp[nex][j][1]
                cp[i+j+1][0] %= mod
                cp[i+j][0] += dp[now][i][0]*dp[nex][j][2]
                cp[i+j][0] %= mod
                cp[i+j+1][2] += dp[now][i][1]*dp[nex][j][0]
                cp[i+j+1][2] %= mod
                cp[i+j][1] += dp[now][i][1]*dp[nex][j][1]
                cp[i+j][1] %= mod
                cp[i+j][1] += dp[now][i][1]*dp[nex][j][2]
                cp[i+j][1] %= mod
                cp[i+j][2] += dp[now][i][2]*dp[nex][j][0]
                cp[i+j][2] %= mod
                cp[i+j][2] += dp[now][i][2]*dp[nex][j][1]
                cp[i+j][2] %= mod
                cp[i+j][2] += dp[now][i][2]*dp[nex][j][2]
                cp[i+j][2] %= mod
        #  cp.pop()
        dp[now] = cp
dfs(0)
for i in range(N+1):
    ans = 0
    for j in range(3):
        ans += dp[0][i][j]
        ans %= mod
    print(ans)
