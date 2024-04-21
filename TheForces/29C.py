from math import *
import sys; R = input
S = lambda: map(int,R().split())
import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 

def solve():
    a, b = S()
    if a > 0 or b > 0 and (log2((a^b) + 1)).is_integer():
        print("YES")
    else:
        print("NO")

for _ in range(int(R())):
    solve()
