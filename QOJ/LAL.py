import sys; R = input
S = lambda: map(int,R().split())

def solve():
    r, c, k = S()
    a = []
    b = []

    for _ in range(r):
        s, t = input().split()
        a.append(s)
        b.append(t)

    all_a = [True]*r
    for i in range(r):
        for j in range(c):
            all_a[i] &= a[i][j] == '*'

    b_on = [False]*r
    for i in range(r):
        for j in range(k):
            b_on[i] |= b[i][j] == '*'

    ok = True
    for i in range(r):
        if b_on[i]:
            ok &= all_a[i]

    print("Y" if ok else "N")

solve()

