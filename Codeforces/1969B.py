import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    s = list(map(int, list(R())))
    where = []
    for i, x in enumerate(s):
        if x == 1:
            where.append(i)
    
    ans = 0
    if where:
        ans += (len(s)-len(where)) - where[0]
    for i,x in enumerate(where):
        ans += (len(s)-len(where)+i)-x

    print(ans)

    

for _ in range(int(R())):
    solve()

