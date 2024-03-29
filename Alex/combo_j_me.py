# AC

import io, sys; R =lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

P = 998244353
mx_n = 10**6
f = [1]
for i in range(1, mx_n+1):
    f.append(f[-1]*i%P)

def solve():
    n = int(R())
    ans = f[n]
    mult = n
    for i in range(1, n-1):
        ans = (ans + (f[n-i]-1)*mult) % P
        mult = (mult*(n-i)) % P

    print(ans)

solve()



