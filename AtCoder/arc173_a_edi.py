def fstTrue(lo, hi, f):
    while lo < hi:
        m = (lo+hi) // 2
        if f(m):
            hi = m
        else:
            lo = m+1
    return lo


# returns how many Neq numbers y that satisfy y < x + 1
def f(x):
    x += 1
    b = []
    while x > 0:
        b.append(x%10)
        x //= 10
    b = list(reversed(b))

    ret = 0
    for k in range(1, len(b)):
        ret += 9**k

    # okay, we only need to count those w/ exactly len(b) digits now
    for k in range(len(b)):
        if k == 0:
            ret += (b[k]-1) * 9**(len(b)-k-1)
        else:
            choices = b[k]
            if b[k-1] <= b[k]-1:
                choices -= 1
            ret += choices * 9**(len(b)-k-1)

            if b[k-1] == b[k]:
                break

    return ret

memo = {}
def count(x, e):
    if x <= 9:
        return x + 1 - (0 < e <= x)
    #  if x < 0:
        #  return 0
    if (x, e) in memo:
        return memo[x, e]
    res = 0
    for i in range(10):
        if i == e:
            if e == 0:
                res += 1
            continue
        res += count((x - i) // 10, i)
    memo[x, e] = res
    return res

# count(x, 10)-1 = f(x)

def solve(n):
    ans = fstTrue(0, int(1e18), lambda x: f(x) >= n)

    return ans

for _ in range(int(input())):
    kth = int(input())
    print(solve(kth))

