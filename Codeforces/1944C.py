from collections import Counter
import sys; R = input
S = lambda: map(int,R().split())

def solve():
    n = int(input())
    a = list(S())
    a.sort()
    st = set(a)
    mex = 0
    while mex in a:
        mex += 1

    second = float('inf')
    c = Counter(a)
    flag = False
    for u, v in sorted(c.items()):
        if v == 1:
            if flag:
                second = u
                break
            flag = True

    print(min(second, mex))

for _ in range(int(input())):
    solve()
