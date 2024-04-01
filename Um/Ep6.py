# Two impl mistakes (and I had to rewrite ...)
# 1. I didn't understand that my claim that it won't exceed mx_nc
#    only holds when you start from valid states
# 2. I didn't realise you can just subtract avg at the beginning

# Learned averages subtracting trick. Don't miss it again.

import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

n, m = S()
a = list(map(lambda x: x - m, S()))
mx_n = 50
mx_c = 50
mx_nc = mx_n * mx_c
dp = [[0]*(2*mx_nc+1) for _ in range(n+1)]
dp[0][mx_nc] = 1

for i in range(n):
    for j in range(-mx_nc, mx_nc+1):
        if not dp[i][mx_nc+j]:
            continue
        dp[i+1][mx_nc + j] += dp[i][mx_nc + j]
        dp[i+1][mx_nc + j + a[i]] += dp[i][mx_nc + j]

print(dp[n][mx_nc] - 1)

