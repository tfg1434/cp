T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))

    pre = a[:]
    for i in range(1, n):
        pre[i] += pre[i-1];

    ans = -1

    for x in pre:
        i = 0
        s = 0
        m = 0

        while i < n:
            s += a[i]
            
            if s == x:
                m += 1
                s = 0
            elif s > x:
                m = -1
                break

            i += 1

        if m > ans: ans = m

    print(n-ans)
