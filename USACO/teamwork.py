# python is a bitch so it doesn't pass

import sys
sys.stdin = open("teamwork.in", "r")
sys.stdout = open("teamwork.out", "w")

def solve():
    n, k = map(int, input().split())
    a = []
    for _ in range(n):
        x = int(input())
        a.append(x)

    mx = [[0]*(n+1) for _ in range(n)]
    for i in range(n):
        x = 0
        for j in range(i, -1, -1):
            x = max(x, a[j])
            mx[j][i+1] = x

    # how many elements considered
    # how many elements in last group
    dp = [[0]*(k+1) for _ in range(n+1)]
    dp[1][1] = a[0]
    for i in range(1, n):
        for j in range(1, min(k+1, i+1)):
            if 0 < j < k:
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] - j*mx[i-j][i] + (j+1)*mx[i-j][i+1])
            dp[i+1][1] = max(dp[i+1][1], dp[i][j]+a[i])

    print(max(dp[n]))

solve()
