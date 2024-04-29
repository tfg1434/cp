import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n = int(R())
    p = list(S())
    p = [x-1 for x in p]
    found = False
    for i in range(n):
        for j in range(i+1, n):
            found |= p[i] == j and p[j] == i

    print(2 if found else 3)

for _ in range(int(R())):
    solve()
