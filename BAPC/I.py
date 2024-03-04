def solve():
    n, m = map(int, input().split())

    if n%2 == 0 and m%2==0:
        return print(-1)

    flip = False
    if n % 2 == 0:
        flip = True
        n, m = m, n

    ans = []
    def f(r, c):
        ans.append((r, c) if not flip else (c, r))

    for i in range(1, n+1, 2):
        if i % 4 == 1:
            for j in range(1, m+1):
                f(i, j)

            if i < n:
                f(i+1, m)
        else:
            for j in range(m, 0, -1):
                f(i, j)

            if i < n:
                f(i+1, 1)

    for i in range(1, n, 2):
        if i % 4 == 1:
            for j in range(m-1, 0, -1):
                f(i+1, j)
        else:
            for j in range(2, m+1):
                f(i+1, j)

    for r, c in ans:
        print(r, c)


for _ in range(int(input())):
    solve()
