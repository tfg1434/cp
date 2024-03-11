from itertools import *

def solve():
    n, k = map(int, input().split())
    s = input()
    t = input()
    a = t[0]
    b = t[1]

    pa = [0]*(n+1)
    pb = [0]*(n+1)
    for i in range(n):
        pa[i+1] = pa[i]+

    dp = [[[0 for _ in range(n+1)] for _ in range(k+1)] for _ in range(k+1)]
    for i in range(n):
        for x in range(k+1):
            for y in range(k+1):
                if x+y > k:
                    break

                dp[i+1][x][y] = max(dp[i+1][x][y], dp[i][x][y]+x+pa[i] if s[i]==b else 0)
                if x+y < k:
                    if (s[i] != a):
                        dp[i+1][x+1][y] = max(dp[i+1][x+1][y], dp[i][x][y])
                    if (s[i] != b):
                        dp[i+1][x][y+1] = max(dp[i+1][x][y+1], dp[i][x][y]+x+pa[i])

    ans = 0
    for x in range(k+1):
        for y in range(k+1):
            ans = max(ans, dp[n][x][y])

    ps(ans)




solve()


