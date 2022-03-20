import sys
import math


MOD = 1000000007

def solve():
    n, u, v = list(map(int, input().split()))
    a = list(map(int, input().split()))

    ans = math.inf
    for i in range(1, n):
        if abs(a[i] - a[i-1]) >= 2: ans = 0
        if abs(a[i] - a[i-1]) == 1: ans = min(ans, min(u, v))
        if a[i] == a[i-1]: ans = min(ans, v + min(u, v))

    print(ans)

for _ in range(int(input())):
    solve()

