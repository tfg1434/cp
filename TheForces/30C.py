import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n = int(R())
    p = [0]*n
    r = n
    while r > 0:
        pos = r//2
        p[pos] = r
        r -= 1
        for j in range(r, pos, -1):
            p[j] = r
            r -= 1

    print(*p)

for _ in range(int(R())):
    solve()


