import sys
import math


MOD = 1000000007

def solve():
    pass

for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    c = len(set(a))

    if k >= c: print(1)
    elif k == 1: print(-1)
    else:
        print(math.ceil((c-1)/(k-1)))

