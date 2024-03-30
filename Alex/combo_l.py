from itertools import *
import sys; R = input
S = lambda: map(int,R().split())

P = 998244353
mx_n = 10**5
f = [1]
for i in range(1, mx_n+1):
    f.append(f[-1]*i%P)
ff = [pow(f[i], P-2, P) for i in range(mx_n+1)]
def C(n, r):
    return f[n]*ff[n-r]%P*ff[r]%P

def solve():
    n = int(R())
    s = R()
    compressed = [(u, len(list(v))) for u, v in groupby(s)]
    candies = sum((uv[1] * (uv[0] == '0')) for uv in compressed)
    compressed = list(filter(lambda uv: uv[0] == '1', compressed))

    if not compressed:
        return print(1)

    baskets = 1
    for u, v in compressed:
        baskets += v//2

    print(C(candies+baskets-1, baskets-1))

for _ in range(int(input())):
    solve()

