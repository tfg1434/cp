from collections import Counter
from itertools import accumulate
import sys
 
def lstTrue(lo, hi, fun):
    lo -= 1
    while lo < hi:
        m = (lo+hi+1)//2
        if fun(m):
            lo = m
        else:
            hi = m-1
    return lo

def solve():
    n = int(input())
    f = Counter(map(int, input().split()))
 
    def fun(k):
        num_blocks = (n+k-1)//k
        last_block = (n-1)%k+1
 
        full_chains = 0
        for x, y in f.most_common():
            if y == num_blocks:
                full_chains += 1
 
        print(k, full_chains, file=sys.stderr)
        return (f.most_common(1)[0][1] <= num_blocks and
                full_chains <= last_block)
 
 
    k = lstTrue(1, n, fun)
    #  k = 1
    #  for i in range(2, n+1):
        #  if fun(i):
            #  k = i
    print(k-1)
 
 
t = int(input())
for _ in range(t):
    solve()
