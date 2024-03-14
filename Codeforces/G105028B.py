def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    nxt = [[-1]*m for _ in range(n)]
    for i in range(n):
        s = []
        for j in range(m):
            s.append(j)
            if b[j] == a[i]:
                while s:
                    nxt[i][s.pop()] = j

        for j in range(m):
            if b[j] == a[i]:
                while s:
                    nxt[i][s.pop()] = j+m


    ans = 1
    cur = 0
    for i in range(n):
        if nxt[i][cur] == -1:
            return print(-1)
        cur = nxt[i][cur]
        if cur >= m:
            ans += 1
            cur -= m

    print(ans)


for _ in range(int(input())):
    solve()



