import sys; R = input
S = lambda: map(int,R().split())

def solve():
    n = int(R())
    a = list(S())

    invs = 0
    def mergesort(l, r):
        nonlocal invs

        if l == r:
            return

        m = (l+r)//2
        mergesort(l, m)
        mergesort(m+1, r)

        j = l
        for i in range(m+1, r+1):
            while j <= m and a[j] <= a[i]:
                j += 1
            invs += m+1-j

        a[l:r+1] = sorted(a[l:r+1])
        
    mergesort(0, n-1)

    print(invs)

        
solve()
