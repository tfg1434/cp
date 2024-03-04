def solve():
    n = int(input())
    a = list(map(int, input().split()))

    if all(x == a[0] for x in a):
        return print(-1)

    cnt = sum(1 if a[i] == i+1 else 0 for i in range(n))
    print((cnt+1)//2)


for _ in range(int(input())):
    solve()
