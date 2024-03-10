# Let dp[x][e] be the number of NONNEGATIVE Neq numbers <= x
# that don't start with e
# 

def fstTrue(lo, hi, f):
    while lo < hi:
        m = (lo+hi) // 2
        if f(m):
            hi = m
        else:
            lo = m+1
    return lo

memo = {}
def dp(x, e):
    assert(x >= 0)
    if x <= 9:
        return x+1-(0 < e <= x)
    if (x, e) in memo:
        return memo[x, e]
    
    res = 0
    for i in range(10):
        if i == e:
            if e == 0:
                res += 1
            continue
        res += dp((x-i)//10, i)

    memo[x, e] = res
    return res

def solve(n):
    ans = fstTrue(0, int(1e18), lambda x: dp(x, 10)-1 >= n)

    return ans

for _ in range(int(input())):
    kth = int(input())
    print(solve(kth))


