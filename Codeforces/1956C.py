import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n = int(R())
    S = sum(i * (2*i-1) for i in range(1, n+1))
    p = [i for i in range(n, 0, -1)]

    print(S, 2*n)
    for i in range(n):
        print(1, i+1, *p)
        print(2, i+1, *p)

for _ in range(int(R())):
    solve()
