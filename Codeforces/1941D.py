def solve():
    n, m, x = map(int, input().split())
    x -= 1

    knapsack = []
    for _ in range(m):
        r, d = input().split()
        r = int(r)

        if d == '1':
            x -= r
        elif d == '0':
            x += r
        else:
            knapsack.append(r%n)
        x %= n

    dp = [0]*n
    dp[x] = 1
    for i, elem in enumerate(knapsack):
        pd = [0]*n
        for j in range(n):
            pd[(j+elem) % n] |= dp[j]
            pd[(j-elem) % n] |= dp[j]
        dp = pd[:]

    ok = []
    for i in range(n):
        if dp[i]:
            ok.append(i+1)

    print(len(ok))
    print(*ok)
    
for _ in range(int(input())):
    solve()

