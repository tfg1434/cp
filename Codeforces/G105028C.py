P = 998244353

def solve():
    n = int(input())
    res = 1
    if n % 2 == 0:
        cur = 0
        for i in range(2, n+1, 2):
            res *= i*i-cur
            res %= P
            cur += 1
            res *= i*i-cur
            res %= P
            cur += 1
    else:
        cur = 1
        for i in range(3, n+1, 2):
            res *= i*i-cur
            res %= P
            cur += 1
            res *= i*i-cur
            res %= P
            cur += 1

    print(res)


for _ in range(int(input())):
    solve()
