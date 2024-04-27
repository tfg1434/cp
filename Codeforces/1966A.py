import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

from collections import Counter

def solve():
    n, k = S()
    a = list(S())
    c = Counter(a)
    if c.most_common()[0][1] >= k:
        print(k-1)
    else:
        print(n)

for _ in range(int(R())):
    solve()
