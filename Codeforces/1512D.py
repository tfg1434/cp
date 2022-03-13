import sys


MOD = 1000000007

def solve():
    n = int(input())
    b = list(map(int, input().split()))
    b.sort()

    sm = sum(b) - 2*b[-1]

    # sum is the biggest
    if sm in b[:-1]:
        b.remove(sm)
        print(*b[:n])
    else:
        if (sum(b[:n]) == b[n]):
            print(*b[:n])
        else:
            print(-1)

for _ in range(int(input())):
    solve()

