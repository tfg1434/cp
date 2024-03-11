from collections import *

class SlidingWindow:
    def __init__(self):
        self.l = 0
        self.r = 0
        self.d = deque()
    
    def append(self, x):
        while self.d and self.d[-1][0] >= x:
            self.d.pop()
        self.d.append((x, self.r))
        self.r += 1

    def popleft(self):
        if self.d[0][1] == self.l:
            self.d.popleft()
        self.l += 1
    
    def ask(self):
        if self.d:
            return self.d[0][0]
        return float('inf')


def solve():
    n, m, k, d = map(int, input().split())
    a = [[] for _ in range(n)]
    for i in range(n):
        a[i] = list(map(int, input().split()))

    wincost = 0
    dp = [[float('inf')]*m for _ in range(n)]
    for i in range(n):
        dp[i][0] = 1
        w = SlidingWindow()
        w.append(dp[i][0])
        for j in range(1, m):
            #  dp[i][j] = min(dp[i][max(0, j-d-1):j]) + a[i][j]+1
            dp[i][j] = w.ask() + a[i][j]+1
            w.append(dp[i][j])
            if j+1 > d+1:
                w.popleft()

        if i < k:
            wincost += dp[i][m-1]

    ans = wincost
    for i in range(n-k):
        wincost -= dp[i][m-1]
        wincost += dp[i+k][m-1]
        ans = min(ans, wincost)

    print(ans)



for _ in range(int(input())):
    solve()

