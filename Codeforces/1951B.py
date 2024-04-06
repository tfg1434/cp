import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n, k = S()
    k -= 1 
    a = list(S())
    
    idx = -1
    for i in range(n):
        if a[i] > a[k]:
            idx = i
            break

    if idx == -1:
        return print(n-1)
    if idx > k:
        return print(idx-1)
    
    ans = max(0, idx-1)
    a[idx], a[k] = a[k], a[idx]
    for i in range(n):
        if a[i] > a[idx]:
            ans = max(ans, i-idx-1+(idx > 0))
            break

    print(ans)

for _ in range(int(R())):
    solve()
