from math import *
import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n = int(R())
    a = list(S())

    for _ in range(int(2*sqrt(max(a)))+1):
        for i in range(1, n+1):
            a[i%n] = max(0, a[i%n]-a[i-1])

    #  if n > 2:
        #  for i in range(n):
            #  assert((a[i] > 0) + (a[i-1] > 0) + (a[i-2] > 0) <= 2)

    for i in range(n):
        if a[i-1] > 0 and a[i] > 0:
            a[i] = 0

    sol = []
    for i, x in enumerate(a):
        if x > 0:
            sol.append(i+1)

    print(len(sol))
    print(*sol)

for _ in range(int(R())):
    solve()
