import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n = int(R())
    print((n+5)//6, (n+3)//4)

for _ in range(int(R())):
    solve()
