import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n, z = S()
    a = list(S())
    ans = max(x | z for x in a)
    print(ans)

for _ in range(int(R())):
    solve()
