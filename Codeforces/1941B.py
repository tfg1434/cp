def solve():
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n-2):
        if a[i] < 0:
            return print("NO")
        a[i+1] -= 2*a[i]
        a[i+2] -= a[i]
        a[i] = 0

    if all(x == 0 for x in a):
        print("YES")
    else:
        print("NO")



for _ in range(int(input())):
    solve()
