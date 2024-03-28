import math
from bisect import *
import sys; R = input
S = lambda: map(int,R().split())

P = 10**9+7
mx_n = 2*10**5
f = [1]
for i in range(1, mx_n+1):
    f.append(f[-1]*i%P)
ff = [pow(f[i], P-2, P) for i in range(mx_n+1)]
def C(n, r):
    return f[n]*ff[n-r]%P*ff[r]%P
# I began writing pascal triangle
#  mx_m = 200
#  C = [[0]*(mx_m+1) for _ in range(mx_n+1)]

def solve():
    n, m, k = S()
    a = sorted(list(S()))
    ans = 0
    for i, x in enumerate(a):
        hi = bisect_right(a, x+k)
        if m-1 <= hi-i-1:
            ans += C(hi-i-1, m-1)
            ans %= P

    print(ans)


for _ in range(int(input())):
    solve()
