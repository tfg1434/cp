def solve():
    n = int(input())

    ans = []
    i = 1
    j = n
    while i <= j:
        ans.append(i)
        ans.append(j)
        j -= 1
        i += 1

    ans = list(reversed(ans))
    if n&1:
        ans = ans[1:]
    print(*ans)


t = int(input())
for _ in range(t):
    solve()
