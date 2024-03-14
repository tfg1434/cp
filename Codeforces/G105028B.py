# this caused me so much grief
# why? duplicates in a :(
# 
# now tle? wtf
# oh i thought they guaranteed the product lmao

from bisect import *

def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    nm = max(n, m)+1

    where = [[] for _ in range(nm)]
    for i in range(m):
        where[b[i]].append(i)

    ans = 1
    if a[0] not in b:
        return print(-1)
    cur = b.index(a[0])

    for i in range(1, n):
        if not where[a[i]]:
            return print(-1)

        idx = bisect_right(where[a[i]], cur)
        if idx >= len(where[a[i]]):
            ans += 1
            idx = 0
        cur = where[a[i]][idx]

    print(ans)


for _ in range(int(input())):
    solve()



