def fstTrue(lo, hi, f):
    while lo < hi:
        m = (lo+hi)//2
        if f(m):
            hi = m
        else:
            lo = m+1
    return lo

def solve():
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    d = list(map(int, input().split()))
    f = list(map(int, input().split()))
    d.sort()
    f.sort()
    
    mx = []
    for i in range(n-1):
        mx.append((a[i+1]-a[i], i))
    mx.sort(reverse=True)

    mean = (a[mx[0][1]] + a[mx[0][1]+1])/2
    dist = float('inf')
    closest = -1
    for i in range(m):
        idx = fstTrue(0, k, lambda j: d[i]+f[j] >= mean)
        if idx < k:
            if d[i]+f[idx]-mean < dist:
                dist = d[i]+f[idx]-mean
                closest = d[i]+f[idx]

        if idx > 0:
            if mean-d[i]-f[idx-1] < dist:
                dist = mean-d[i]-f[idx-1]
                closest = d[i]+f[idx-1]

    assert(closest != -1)
    #  print(closest)
    x = closest - a[mx[0][1]]
    y = a[mx[0][1]+1] - closest
    if x > 0 and y > 0:
        mx.append((x, -1))
        mx.append((y, -1))
        mx.pop(0)
        mx.sort(reverse=True)

    print(mx[0][0])


for _ in range(int(input())):
    solve()

