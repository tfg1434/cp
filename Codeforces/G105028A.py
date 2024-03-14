def solve():
    n, k = map(int, input().split())
    x = k//2

    ans = x*(x+1)
    if k & 1:
        ans += x+1

    print(ans)

for _ in range(int(input())):
    solve()
