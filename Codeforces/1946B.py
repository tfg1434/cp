import sys; R = input
S = lambda: map(int,R().split())

P = 10**9 + 7

def solve():
    n, k = S()
    a = list(S())

    mx = 0
    cur = 0
    for i in range(n):
        cur += a[i]
        cur = max(0, cur)
        mx = max(mx, cur)
    
    mx %= P
    ap = pow(2, k, P) - 1
    print((sum(a) + ap*mx) % P)

for _ in range(int(input())):
    solve()
