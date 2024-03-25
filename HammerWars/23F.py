from itertools import *

import sys; R = input
S = lambda: map(int,R().split())

def solve():
    n = int(input())
    A = list(S())
    B = list(S())
    a = []
    for i in range(n):
        a.append((A[i]-B[i], A[i], B[i]))

    a.sort(key=lambda x:x[0])
    pre_a = [0]*(n+1)
    for i in range(1, n+1):
        pre_a[i] = pre_a[i-1]+a[i-1][1]

    suf_b = [0]*(n+1)
    for i in range(n-1, -1, -1):
        suf_b[i] = a[i][2]
        if i < n-1:
            suf_b[i] += suf_b[i+1]

    ans = float('inf')
    for i in range(n):
        penalty = i*(i+1)//2 + (n-i-1)*(n-i-2)//2
        ans = min(ans, pre_a[i+1]+suf_b[i+1]+penalty)

    print(ans)

for _ in range(int(input())):    
    solve()
