import sys; R = input
S = lambda: map(int,R().split())

P = 10**9+7
MX = 2*10**5
f = [1]
for i in range(1, MX+1):
    f.append(f[-1]*i%P)
ff = [0]*(MX+1)
ff[MX] = pow(f[MX], P-2, P)
for i in range(MX-1, -1, -1):
    ff[i] = ff[i+1]*(i+1) % P

p2 = [1]
for i in range(1, MX+1):
    p2.append(p2[-1]*2%P)

def C(n, r):
    return f[n]*ff[n-r]%P*ff[r]%P
assert(C(10, 0) == 1)
assert(C(10, 5) == 252)

def solve():
    n, m = S()
    if m == 0:
        return print(1)

    if n % 2 == 0:
        eq = pow(p2[n-1] - 1, m, P)
    else:
        eq = pow(p2[n-1] + 1, m, P)

    gt = 0
    if n % 2 == 0:
        for k in range(m):
            gt = (gt + pow(p2[n-1]-1, k, P) * pow(p2[n], m-k-1, P)) % P

    print((gt+eq) % P)


for _ in range(int(R())):
    solve()

