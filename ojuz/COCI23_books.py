from itertools import accumulate 

def fstTrue(lo, hi, f):
    hi += 1
    while lo < hi:
        m = (lo+hi)//2
        if f(m): 
            hi = m
        else: 
            lo = m+1

    return lo

#  tcTU> T lstTrue(T lo, T hi, U f) {
    #  --lo; assert(lo <= hi); // assuming f is decreasing
    #  while (lo < hi) { // find first index such that f is true 
        #  T mid = lo+(hi-lo+1)/2;
        #  f(mid) ? lo = mid : hi = mid-1;
    #  } 
    #  return lo;
#  }

def lstTrue(lo, hi, f):
    lo -= 1
    while lo < hi:
        m = lo+(hi-lo+1)//2
        if f(m):
            lo = m
        else:
            hi = m-1
    return lo

def solve():
    n, t, a, b = map(int, input().split())
    v = list(map(int, input().split()))
    f =  list(accumulate(v))
    f.insert(0, 0)

    ans = 0
    for r in range(0, n):
        first_read = fstTrue(0, r, lambda j: (r-j+1)*a + b*max(0,j) <= t)
        #  print(r, first_read)

        x = f[r+1]
        x -= f[first_read]
        ans = max(ans, x)

    print(ans)

for _ in range(1):
    solve()


