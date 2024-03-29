import math
import sys; R = input
S = lambda: map(int,R().split())

P = 998244353
mx_n = 10**6
f = [1]
for i in range(1, mx_n+1):
    f.append(f[-1]*i%P)
ff = [pow(f[i], P-2, P) for i in range(mx_n+1)]
def C(n, r):
    return f[n]*ff[n-r]%P*ff[r]%P

def solve():
    n = int(R())
    dec = 0
    for i in range(1, n):
        dec = (dec + f[n]*ff[i]) % P

    print((n*f[n] - dec) % P)

solve()
