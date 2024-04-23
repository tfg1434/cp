import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

from collections import Counter

def solve():
    n = int(R())
    a = list(S())

    cnt = Counter(a)
    ans = 0
    for u, v in cnt.items():
        ans += v//3
    print(ans)

for _ in range(int(R())):
    solve()
