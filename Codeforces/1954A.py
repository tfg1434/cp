import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n, m, k = S()
    q = n//m
    r = n%m
    Q = q
    if r > 0:
        Q += 1

    print("NO" if k >= n-Q else "YES")

for _ in range(int(R())):
    solve()
