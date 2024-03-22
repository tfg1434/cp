import sys; R = input
S = lambda: map(int,R().split())

P = 998244353

def solve():
    n, k, l = S()
    ans = 1
    for i in range(n):
        ways = l-min(i, n-k)
        if ways <= 0:
            return print(0)
        ans *= ways
        ans %= P

    print(ans)

solve()
