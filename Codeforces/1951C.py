import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n, m, k = list(S())
    a = list(S())
    b = [(x, -i) for i, x in enumerate(a)]
    b.sort()
    c = [0]*n
    
    for x, i in b:
        c[-i] = min(m, k)
        k -= c[-i]
        if not k:
            break

    ans = 0
    off = 0
    for i in range(n):
        ans += c[i]*(off+a[i])
        off += c[i]

    print(ans)

for _ in range(int(R())):
    solve()

