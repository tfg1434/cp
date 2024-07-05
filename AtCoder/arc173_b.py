from itertools import *

def solve():
    n = int(input())
    p = []
    for _ in range(n):
        x, y = map(int, input().split())
        p.append((x, y))

    mx = 0
    for (x1, y1), (x2, y2) in product(p, repeat=2):
        if (x1, y1) == (x2, y2):
            continue

        cnt = 2
        for (x3, y3) in p:
            if (x3, y3) == (x1, y1) or (x3, y3) == (x2, y2):
                continue
            if (y3-y1)*(x3-x2) == (x3-x1)*(y3-y2):
                cnt += 1

        mx = max(mx, cnt)


    print(min(n-mx, n//3))

solve()


