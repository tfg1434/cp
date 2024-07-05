P = 998244353

def solve():
    n = int(input())
    a = map(int, input().split())
    a = [x-1 for x in a]

    where = [[] for _ in range(n)]
    for i in range(n):
        if a[i] < i:
            return 0
        where[a[i]].append(i)

    s, t = [], []
    for i in range(n):
        if len(where[i]) == 0:
            continue
        if where[i][-1] < i:
            return 0
        s.append(where[i][0])
        t.append(where[i][-1])

    s.sort()
    t.sort()

    ans = 1
    occupied = 0
    cur = 0
    for i, x in enumerate(t):
        while cur < len(s) and s[cur] <= x:
            cur += 1
        ans *= cur-occupied
        ans %= P
        occupied += 1

    return ans

print(solve())
