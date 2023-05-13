

for _ in range(int(input())):
    ans = -1
    n = int(input())
    for i in range(1, 10):
        x = i;
        if (x > n): break
        while (10*x+i < n):
            x = 10*x+i

        m = n - x
        if len(set(str(m))) == 1 and m != 0 and m != n:
            ans = m

    print(ans, n-ans)
