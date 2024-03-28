"""
Fix the (attained) minimum, then count how many ways
"""

import math
import sys; R = input
from bisect import *
S = lambda: map(int,R().split())

def solve():
    _ = S()
    a = [sorted(list(S())) for _ in range(3)]

    ans = 0
    for i in range(3):
        for j, x in enumerate(a[i]):
            mn = x
 
            res = 1
            for k in range(3):
                lo = bisect_left(a[k], mn)
                hi = bisect_right(a[k], 2*mn)
                cnt = k+1 - (k == i)
                choices = hi - lo - (i == k)
                if choices < cnt:
                    res = 0
                    break
                res *= math.comb(hi-lo - (i == k), cnt)
            
            ans += res
            #  print(x, res)

    print(ans)
            

solve()
