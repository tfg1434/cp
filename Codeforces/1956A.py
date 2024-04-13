import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n, q = S()
    a = list(S())
    
    for m in S():
        print(min(m, a[0]-1), end=" ")

    print()

for _ in range(int(R())):
    solve()
