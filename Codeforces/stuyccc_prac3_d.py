from functools import *
from math import *

@lru_cache(maxsize=None)
def ask(i, j):
    assert(i < j)
    print("?", i, j, flush=True)
    res = int(input())
    return res

n = int(input())
P = 0
pos = -1
ans = [0]*(n+1)
for i in range(2, n+1):
    l = ask(1, i)

    primes = []
    for j in range(2, int(sqrt(l)+1)):
        if l % j == 0:
            while l % j == 0:
                l //= j
            primes.append(j)
            
    if l > 1:
        primes.append(l)

    if max(primes) > P:
        P = max(primes)
        pos = i

if ask(1, 2) % P == 0 and ask(1, 3) % P == 0:
    pos = 1

ans[pos] = P
for i in range(1, n+1):
    if i == pos:
        continue
    ans[i] = ask(min(pos, i), max(pos, i)) // P

print('!', *ans[1:], flush=True)




