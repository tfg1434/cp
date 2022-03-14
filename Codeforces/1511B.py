import sys


MOD = 1000000007

def solve():
    ca, cb, cc = map(int, input().split())

    a = 1
    b = 1
    for _ in range(ca - cc): a *= 10
    for _ in range(cb - cc): 
        b *= 10
        b += 1
    for _ in range(cc - 1):
        a *= 10
        b *= 10

    print(a, b, end=" ")
    print()

for _ in range(int(input())):
    solve()

