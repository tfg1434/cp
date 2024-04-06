import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n, k = S()
    if n == k:
        print("YES")
        print(1)
        return print(1)

    if k <= (n+1)//2:
        print("YES")
        print(2)
        return print(n-k+1, 1)

    print("NO")

for _ in range(int(R())):
    solve()

