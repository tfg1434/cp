import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

# 12121
def solve():
    n = int(R())
    a = list(S())

    if all(a[i] == a[0] for i in range(1, n)):
        return print(-1)

    mn = float('inf')
    cur = 0
    for i in range(n):
        if a[i] == a[0]:
            cur += 1
        else:
            mn = min(mn, cur)
            cur = 0
    mn = min(mn, cur)

    print(mn)


for _ in range(int(R())):
    solve()
                
