import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n = R()
    s = R()
    cnt = sum(1 if c=='1' else 0 for c in s)
    if cnt % 2 == 1:
        return print("NO")
    if cnt == 2 and s.find("11") != -1:
        return print("NO")
    print("YES")

for _ in range(int(R())):
    solve()
