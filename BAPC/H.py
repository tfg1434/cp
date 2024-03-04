def solve():
    n, k = map(int, input().split())
    if k > n*n:
        return print("NO")

    if n*n == k:
        return print("YES")

    if n & 1:
        return print("YES") if k % 4 <= 1 else print("NO")
    else:
        return print("YES") if k % 4 == 0 else print("NO")


for _ in range(int(input())):
    solve()

