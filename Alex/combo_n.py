import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n, p = S()
    f = [1]
    for i in range(1, n+1):
        f.append(f[-1]*i%p)
    ff = [pow(f[i], p-2, p) for i in range(n+1)]
    def C(n, r):
        return f[n]*ff[n-r]%p*ff[r]%p
    
    ans = 0

    if n % 2 == 1:
        for i in range(n//2, n-1):
            for j in range(n-i-1):
                ans = (ans + n*C(n-i-2, j)*(2*(n//2) - i)*f[i+j-1]) % p
    else:
        ans = n*f[n-2]%p
        for i in range(n//2, n-1):
            for j in range(n-i-1):
                ans = (ans + n*C(n-i-2, j)*(2*(n//2) - i)*f[i+j-1]) % p

    print(ans)

solve()



