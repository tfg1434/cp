import math

def po2(x):
    res = 0
    while x % 2 == 0:
        res += 1
        x /= 2
    return res

def solve():
    x, y = map(int, input().split())
    a, b = po2(x), po2(y)

    if x == 2**a and y == 2**b:
        return print(a-b)
    if x == 2**a:
        return print("-inf")
    if y == 2**b:
        return print("inf")

    if a != b:
        return print("inf" if a < b else "-inf")

    return print(-1*(x//(2**a) - y//(2**b)) // 2)


for _ in range(int(input())):
    solve()



