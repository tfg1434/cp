import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

P = 10**9+7
max_n = 3*10**5

f = [1]
for i in range(1, max_n+1):
    f.append(f[-1]*i % P)
ff = [0]*(max_n+1)
for i in range(0, max_n+1):
    ff[i] = pow(f[i], P-2, P)
def C(n, r):
    return f[n]*ff[n-r]*ff[r] % P

def solve():
    n, k = S()
    for _ in range(k):
        r, c = S()
        if r == c:
            n -= 1
        else:
            n -= 2

    ans = 0
    if n % 2 == 0:
        for d in range(0, n+1, 2):
            ans += C(n, d) * f[n-d] * ff[(n-d)//2]
            ans %= P
    else:
        for d in range(1, n+1, 2):
            ans += C(n, d) * f[n-d] * ff[(n-d)//2]
            ans %= P

    print(ans)

for _ in range(int(R())):
    solve()
