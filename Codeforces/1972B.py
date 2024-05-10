def solve():
    n = int(input())
    s = input()

    U = 0
    D = 0
    for x in s:
        if x == 'U':
            U += 1
        else:
            D += 1

    if U % 2 == 0:
        print("NO")
    else:
        print("YES")

for _ in range(int(input())):
    solve()
