import sys; R = input
S = lambda: map(int,R().split())

def solve():
    n, m = S()
    chasers = list(S())
    lc = [float('inf')]*2
    rc = [-float('inf')]*2
    for c in chasers:
        lc[c%2] = min(lc[c%2], c)
        rc[c%2] = max(rc[c%2], c)

    runners = list(S())
    ok = True
    for c in runners:
        ok &= lc[c%2] <= c and c <= rc[c%2]

    print("YES" if ok else "NO")

for _ in range(int(input())):
    solve()



