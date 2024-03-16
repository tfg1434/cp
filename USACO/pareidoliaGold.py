from math import *
import sys; R = input
S = lambda: map(int,R().split())

s = R()
n = len(s)
cost = [*S()]

# i letters considered, prefix of first j letters of "bessie"
dp = [[[float('inf'), float('inf')]]*7 for _ in range(n+1)]
dp[0][6] = [0, 0] # zero occurrences of bessie, cost is 0

for i in range(n):
    for j in range(1, 7):
        dp[i+1][j] = min(dp[i+1][j], [dp[i][j][0], dp[i][j][1] + (cost[i] if j != 6 else 0)])
        if j == 6 and s[i] == 'b':
            dp[i+1][1] = min(dp[i+1][1], dp[i][6])
        if 1 <= j <= 4 and s[i] == "bessie"[j]:
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j])
        if j == 5 and s[i] == "e":
            dp[i+1][6] = min(dp[i+1][6], [dp[i][j][0]-1, dp[i][j][1]])

ans = min(dp[n])
print(-ans[0])
print(ans[1])

