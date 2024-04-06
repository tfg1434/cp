import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n = int(R())
    s = R()
    S = s[::-1]

    if s == S:
        print(s)
    elif s < S:
        if n % 2 == 0:
            print(s)
        else:
            print(s+S)
    elif s > S:
        if n % 2 == 1:
            print(S)
        else:
            print(S+s)

for _ in range(int(R())):
    solve()
