def solve():
    n = int(input())
    a = list(map(int, input().split()))

    if (sum(a) == 0):
        print(0)
        return
    else:
        print(max(2 * max(a) - sum(a), 1))

for _ in range(int(input())):
    solve()
