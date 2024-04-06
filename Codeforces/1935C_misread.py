# FUCK i misread that p can be any order

import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n, L = S()
    a = [0]*n
    b = [0]*n
    for i in range(n):
        a[i], b[i] = S()

    # dp(i, last) = max pair (number of messages processed, -time spent in messenger)
    #               if we've processed i elems and the last read message was the last-th one
    dp = [[[0, -float('inf')]*2 for _ in range(n+1)] for _ in range(n+1)]
    dp[0][0] = [0, 0]
    for i in range(n):
        for lasth in range(0, i+1):
            if lasth > 0:
                new_time = -dp[i][lasth][1] + a[i] + abs(b[i]-b[lasth-1])
            else:
                new_time = -dp[i][lasth][1] + a[i]
            if new_time <= L:
                dp[i+1][i+1] = max(dp[i+1][i+1], [dp[i][lasth][0]+1, -new_time])

            dp[i+1][lasth] = max(dp[i+1][lasth], dp[i][lasth])

    print(max(dp[n][lasth] for lasth in range(n+1))[0])

for _ in range(int(R())):
    solve()
