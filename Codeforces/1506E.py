from collections import deque
import sys
import math


MOD = 1000000007

def solve():
    n = int(input())
    q = list(map(int, input().split()))

    mn, mx = [], []
    a = 0
    p1, p2 = deque(), deque()
    for i in range(n):
        c = q[i]
        if c == a: 
            mn.append(p1.popleft())
            mx.append(p2.pop())
        else:
            mn.append(c)
            mx.append(c)
            for j in range(a+1, c):
                p1.append(j)
                p2.append(j)
            a = c

    print(*mn)
    print(*mx)

for _ in range(int(input())):
    solve()

