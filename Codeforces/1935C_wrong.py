# crying...
# the following is false:
# it's always optimal to have an extra message read than less time messaging

from bisect import *
import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n, L = S()
    ab = []
    for i in range(n):
        x, y = S()
        ab.append([x, y])
    ab.sort(key=lambda x:x[1])

    # dp(i, lasth) = max pair (number of messages processed, -time spent messaging)
    #                if we've processed i elems and the last elem selected was the lasth-th one
    dp = [[[0, -float('inf')]*2 for _ in range(n+1)] for _ in range(n+1)]
    dp[0][0] = [0, 0]
    for i in range(n):
        for lasth in range(0, i+1):
            dp[i+1][lasth] = max(dp[i+1][lasth], dp[i][lasth])

            new_time = -dp[i][lasth][1] + ab[i][0]
            new_time += ab[i][1] - (0 if not lasth else ab[lasth - 1][1])
            if new_time <= L:
                dp[i+1][i+1] = max(dp[i+1][i+1], [dp[i][lasth][0]+1, -new_time])

    print(max(dp[n][lasth][0] for lasth in range(0, n+1)))

for _ in range(int(R())):
    solve()
