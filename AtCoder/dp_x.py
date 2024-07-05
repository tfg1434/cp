MAX_S = 20002

def solve():
    n = int(input())

    a = []
    for _ in range(n):
        w, s, v = map(int, input().split())
        a.append((w+s, w, s, v))

    a.sort()

    # dp(i, w)
    dp = [[0 for i in range(MAX_S)] for j in range(n+1)]

    for i in range(n):
        for j in range(MAX_S):
            dp[i+1][j] = dp[i][j]
        for j in range(MAX_S - a[i][1]):
            if a[i][2] < j:
                break
            dp[i+1][j+a[i][1]] = max(dp[i+1][j+a[i][1]], dp[i][j]+a[i][3])

    print(max(dp[n]))



solve()
