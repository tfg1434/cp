import math
import sys; R = input
S = lambda: map(int,R().split())

def solve():
    n, k = S()
    a = list(S())
    dp = [[[float('inf')]*(k+1) for _ in range(3)] for _ in range(n+1)]
    dp[0][0][k] = 0
    for i in range(n):
        for j in range(0+(i != 0), 3):
            for s in range(k+1):
                dist = a[i] - a[i-1] - j if i > 0 else a[i] - j
                if dist <= 0:
                    continue

                for ss in range(min(s, (dist+2)//3)+1):
                    d = dist-ss*3
                    if d == 0:
                        continue

                    if d < 0:
                        dp[i+1][-d][s-ss] = min(dp[i+1][-d][s-ss], dp[i][j][s]+ss)
                        if d == -2 and i+1 < n and a[i+1]-a[i] == 1 and s > ss:
                            dp[i+2][1][s-ss-1] = min(dp[i+2][1][s-ss-1], dp[i][j][s]+ss)
                    else:
                        dp[i+1][1][s-ss] = min(dp[i+1][1][s-ss], dp[i][j][s]+ss+d//2+1)
                        if i+1 < n and a[i+1]-a[i] == 1 and s > ss:
                            dp[i+2][1][s-ss-1] = min(dp[i+2][1][s-ss-1], dp[i][j][s]+ss+d//2+1)

    ans = min(dp[n][1])
    if math.isinf(ans):
        ans = -1
    print(ans)

    

for _ in range(int(input())):
    solve()




