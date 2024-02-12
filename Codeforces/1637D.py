def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    for i in range(n):
        if a[i] > b[i]:
            a[i], b[i] = b[i], a[i]

    # boolean dp
    MAX = 100*n+1
    dp = [[0]*MAX for i in range(n+1)]

    dp[0][0] = 1
    for i in range(1, n+1):
        for j in range(MAX):
            if j-a[i-1] >= 0: dp[i][j] |= dp[i-1][j-a[i-1]]
            if j-b[i-1] >= 0: dp[i][j] |= dp[i-1][j-b[i-1]]
            #  if j+a[i-1] < MAX: dp[i][j] |= dp[i-1][j+a[i-1]]
            #  if j+b[i-1] < MAX: dp[i][j] |= dp[i-1][j+b[i-1]]

    S = sum(a)+sum(b)
    best = float('inf')
    closest = 0
    for i in range(MAX):
        if not dp[n][i]:
            continue

        if abs(S - 2*i) < best:
            best = abs(S-2*i)
            closest = i

    cost = (n-2)*sum(a[i]*a[i]+b[i]*b[i] for i in range(n))
    cost += closest**2
    cost += (S-closest)**2

    #  print(best)
    print(cost)

t = int(input())
for _ in range(t):
    solve()
