from math import *

def isSquare(x):
    return int(0.5 + sqrt(x)) ** 2 == x

def solve():
    n = int(input())
    if n % 2 == 0 and isSquare(n/2):
        print("YES")
    elif n % 4 == 0 and isSquare(n/4):
        print("YES")
    else:
        print("NO")

for _ in range(int(input())):
    solve()
