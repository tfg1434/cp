import sys; R = input
S = lambda: map(int,R().split())
import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 

def solve():
    m, d = S()
    if m == 4 and d == 1:
        return print("YES")
    print("NO")

solve()
