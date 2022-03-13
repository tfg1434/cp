from math import factorial

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    y = a[0]
    for x in a: y &= x

    cnt = a.count(y)
    if cnt < 2:
        print(0)
    else:
        print(((factorial(n-2)) * cnt * (cnt-1)) % (1000000007))

for _ in range(int(input())):
    solve()
