def solve():
    T, G = map(int, input().split())
    n = int(input())

    p = []
    ans = []
    for i in range(n):
        x, y = map(int, input().split())
        p.append(x+y*1j)
        ans.append(i+1)
        if i < 2:
            continue

        for j in range(i, 1, -1):
            a = p[j-2]-p[j-1]
            b = p[j]-p[j-1]
            if a.real*b.real + a.imag*b.imag <= 0:
                p[j], p[j-1] = p[j-1], p[j]
                ans[j], ans[j-1] = ans[j-1], ans[j]
        # print(*ans)
    
    print(*ans)


solve()
