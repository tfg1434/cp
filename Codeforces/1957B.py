import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

from collections import Counter

def solve():
    n, k = S()
    if n == 1:
        return print(k)
    
    sol = [0]
    for i in range(30):
        if sol[0] + (1 << i) <= k:
            sol[0] += (1 << i)
    sol.append(k-sol[0])
    while len(sol) < n:
        sol.append(0)
    print(*sol)

for _ in range(int(R())):
    solve()
