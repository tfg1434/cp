import math

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    ans = [float('inf')]*n
    for i in range(n):
        lo = i
        cur = 0
        all_same = True
        ok = True
        while cur <= a[i] or all_same:
            lo -= 1
            if lo < 0:
                ok = False
                break

            cur += a[lo]
            if a[lo] != a[i-1]:
                all_same = False
            if a[lo] > a[i]:
                all_same = False
        if ok:
            ans[i] = min(ans[i], i-lo)

        hi = i
        cur = 0
        all_same = True
        ok = True
        while cur <= a[i] or all_same:
            hi += 1
            if hi >= n:
                ok = False
                break

            cur += a[hi]
            if a[hi] != a[i+1]:
                all_same = False
            if a[hi] > a[i]:
                all_same = False
        if ok:
            ans[i] = min(ans[i], hi-i)

    ans = (-1 if math.isinf(x) else x for x in ans)
    print(*ans)
        

for _ in range(int(input())):
    solve()

