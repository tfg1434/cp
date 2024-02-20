from collections import Counter
from itertools import accumulate
import sys
 
def solve():
    n, m, k = map(int, input().split())
    f = list(map(int, input().split()))
 
    def fun(k):
        num_blocks = (n+k-1)//k
        last_block = (n-1)%k+1
 
        full_chains = 0
        for y in f:
            if y == num_blocks:
                full_chains += 1
 
        return (max(f) <= num_blocks and
                full_chains <= last_block)
 
 
    print("YES" if fun(k) else "NO")
 
 
t = int(input())
for _ in range(t):
    solve()
