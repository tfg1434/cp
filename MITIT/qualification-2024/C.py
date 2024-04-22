import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

from itertools import *

def solve():
    n, m = S()
    a = list(S())
    a.sort()
    a = [(u, len(list(v))) for u, v in groupby(a)]
    print(a)
    for k in range(1, n+1):
        cur = 0
        sol = []
        K = k

        i = 0
        while len(sol) < m:
            if cur+K <= a[i][1]:
                cur += K
                sol.append(a[i][0])
            else:
                cur += K
                while cur > a[i][1]:
                    K = cur-a[i][1]
                    cur -= a[i][1]
                    i += 1
                sol.append(a[i][0])

        print(*sol)

solve()



