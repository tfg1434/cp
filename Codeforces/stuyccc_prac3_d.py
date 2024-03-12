#!/opt/homebrew/bin/python3

from functools import *
from math import *

@lru_cache(maxsize=None)
def ask(i, j):
    i += 1
    j += 1
    assert(i < j)
    print("?", i, j, flush=True)
    res = int(input())
    return res

n = int(input())

primes = []
pf = [[] for _ in range(n+1)]
for i in range(2, n+1):
    if pf[i]:
        continue
    primes.append(i)
    for j in range(i, n+1, i):
        pf[j].append(i)

P = primes[-1]
assert(2*P > n)

pos = -1
ans = [0]*n
if ask(0, 1) % P == 0 and ask(0, 2) % P == 0:
    pos = 0
else:
    for i in range(1, n):
        if ask(0, i) % P == 0:
            pos = i

assert(pos != -1)
ans[pos] = P

for i in range(0, n):
    if i == pos:
        continue
    ans[i] = ask(min(pos, i), max(pos, i)) // P

print('!', *ans, flush=True)




