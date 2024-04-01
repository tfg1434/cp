from functools import *
import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

n, l, r = S()
a = list(S())

def calc(r):
    res = 0
    for i in range(0, 2**17):
        xor = reduce(lambda x, y: (x^i)+(y^i), a)

        res += max(0, (r-xor) // 2**17) + (xor <= r)
    return res

ans = calc(r)
if l > 0:
    ans -= calc(l-1)
print(ans)
