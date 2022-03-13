import sys


MOD = 1000000007

def solve():
    n, m = map(int, input().split())
    
    d = {}
    a = list(map(int, input().split()))
    for (i, x) in enumerate(a):
        if x not in d:
            d[x] = i+1
    
    t = list(map(int, input().split()))
    for x in t:
        # x is colour, d[x] is position
        print(d[x], end=' ')
        for c in d:
            if d[c] < d[x]:
                d[c] += 1
        d[x] = 1

    print()

solve()

