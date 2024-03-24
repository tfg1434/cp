import sys; R = input
S = lambda: map(int,R().split())

def solve():
    n = int(input())
    ans = 21*n
    if n > 1:
        ans -= 2
    if n > 2:
        ans -= 7*(n-2)

    print(ans/6)

solve()

