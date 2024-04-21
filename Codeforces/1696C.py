import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n, m = S()
    a = list(S())
    k = int(R())
    b = list(S())

    M = set()
    cur = 1
    while cur <= 1e9:
        M.add(cur)
        cur *= m

    pairs = []
    for i, x in enumerate(a):
        pairs.append([x, 1])
        while pairs[-1][0] % m == 0:
            pairs[-1][1] *= m
            pairs[-1][0] //= m

        if len(pairs) > 1 and pairs[-1][0] == pairs[-2][0]:
            pairs[-2][1] += pairs[-1][1]
            pairs.pop()

    if sum(a) != sum(b):
        return print("No")

    j = 0
    for i in range(len(b)):
        if b[i] % pairs[j][0]:
            return print("No")
        x = b[i]//pairs[j][0]
        if pairs[j][1] < x:
            return print("No")
        if x not in M:
            return print("No")
        pairs[j][1] -= x
        if not pairs[j][1]:
            j += 1
    return print("Yes")

for _ in range(int(R())):
    solve()
