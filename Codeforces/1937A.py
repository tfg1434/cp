import math
import sys; R = input
S = lambda: map(int,R().split())

def solve():
    n = int(input())
    print (2**int(math.log2(n)))

for _ in range(int(input())):
    solve()

