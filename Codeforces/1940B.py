def solve():
    n = int(input())
    d = list(map(int, input().split()))
    l = list(map(int, input().split()))
    r = list(map(int, input().split()))
    a0, b0 = map(int, input().split())

    d = [0]+d
    l = [a0]+l
    r = [b0]+r

    # sum of d from i+1..n
    s = [0]*(n+1)
    for i in range(n-1, -1, -1):
        s[i] = s[i+1] + d[i+1];

    x = [l[i]+s[i] for i in range(n+1)]
    print(s)
    print(x)
    y = [r[i]+s[i] for i in range(n+1)]
    z = [[x[i], y[i]] for i in range(n+1)]
    z.sort(reverse=True)

    suf = [float('inf')]*(n+1)
    suf[n] = z[n][1]
    for i in range(n-1, -1, -1):
        suf[i] = min(suf[i+1], z[i][1])

    ans = 0
    for i in range(n+1):
        fin_a = z[i][0]
        fin_b = b0+s[0];
        if i < n:
            fin_b = min(fin_b, suf[i+1])

        print(fin_a, fin_b)
        ans = max(ans, fin_a+fin_b)

    print(ans)




solve()

