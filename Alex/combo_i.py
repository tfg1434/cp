import sys; R = input
S = lambda: map(int,R().split())

MX = 2*10**5
P = 10**9+7
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
    f, w, h = S()

    if w == 0:
        return print(1)
    if h == 0:
        return print(1)
    if f == 0:
        return print(1 if w > h else 0)

    F = [0]*(max(w+2, f+1))
    # F[i] = ways to put food into i baskets
    for i in range(1, f+1):
        F[i] = C(f-1, i-1)

    ways = 0
    tot = 0
    # W = how many baskets of wine 
    for W in range(1, w+1):
        # ways to put wine in W baskets so each basket
        # has > h wine bottles
        each_h = 0
        if W*(h+1) <= w:
            each_h = C(w-W*h - 1, W-1)

        ways_food = F[W-1]+2*F[W]+F[W+1]
        ways += ways_food*each_h % P
        if ways >= P:
            ways -= P

        tot += C(w-1, W-1) * ways_food % P
        if tot >= P:
            tot -= P

    #  print(ways, tot)
    print(ways * pow(tot, P-2, P) % P)

solve()

