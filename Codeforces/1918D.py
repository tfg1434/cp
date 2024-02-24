from collections import deque
from itertools import accumulate

class Window:
    def __init__(self):
        self.l = 0
        self.r = 0
        self.deq = deque()

    def pop(self):
        if self.deq[0][1] == self.l:
            self.deq.popleft()
        self.l += 1

    def append(self, x):
        while self.deq and self.deq[-1][0] >= x:
            self.deq.pop()
        self.deq.append((x, self.r))
        self.r += 1

    def get_min(self):
        return self.deq[0][0] if self.deq else float('inf')

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    a.insert(0, 0)
    pre = list(accumulate(a))

    # whether ans <= k
    def check(k):
        # number taken -> min sum
        dp = [float('inf')]*(n+1)
        dp[0] = 0
        
        j = 0
        w = Window()
        w.append(0)
        for i in range(1, n+1):
            while pre[i-1]-pre[j] > k:
                w.pop()
                j += 1

            dp[i] = a[i]+w.get_min()
            w.append(dp[i])


        res = float('inf')
        x = 0
        for i in range(n, 0, -1):
            res = min(res, dp[i])
            x += a[i]
            if x > k:
                break


        return res <= k
            

    lo = 1
    hi = int(1e14)
    while lo < hi:
        m = (lo+hi)//2
        if check(m):
            hi = m
        else:
            lo = m+1
    print(lo)


t = int(input())
for _ in range(t):
    solve()
