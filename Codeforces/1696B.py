import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n = int(R())
    a = list(S())
    if all(x == 0 for x in a):
        return print(0)

    cnt = sum(1 if x == 0 else 0 for x in a)

    l = 0
    r = n-1
    while a[l] == 0:
        l += 1
    while a[r] == 0:
        r -= 1
    if cnt == l + n-1-r:
        return print(1)

    return print(2)

for _ in range(int(R())):
    solve()
