import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n = int(R())
    a = list(S())
    print(n - len(set(a)))

for _ in range(int(R())):
    solve()
