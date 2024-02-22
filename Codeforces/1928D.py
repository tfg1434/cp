def C(x):
    return x*(x-1)//2

def solve():
    n, b, g = map(int, input().split())
    c = list(map(int, input().split()))
    c.sort(reverse=True)

    def calc(k):
        res = 0
        for x in c:
            cont = C(x)
            cont -= C(x//k+1)*(x%k)
            cont -= C(x//k)*(k-x%k)
            res += cont*b

        res -= (k-1)*g
        return res
    
    ans = 0
    lo, hi = 1, sum(c)+1
    while (lo < hi):
        m = (lo+hi)//2
        if calc(m) > calc(m+1):
            hi = m
        else:
            lo = m+1
    print(calc(lo))


    #  for k in range(1, sum(c)+1):
        #  ans = max(ans, calc(k))

    #  print(ans)


t = int(input())
for _ in range(t):
    solve()

