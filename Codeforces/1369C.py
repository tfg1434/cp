t = int(input())
for tc in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    w = list(map(int, input().split()))
    a.sort(reverse = True)
    w.sort()
    ii, l, r = k, 0, n-1
    ans = 0
    for i in range(k):
        if(w[i] > 1):
            ii = i
            break
        ans = ans+a[l]*2
        l = l+1

    print(ans)
    for u in range(k-1, ii-1, -1):
        i = w[u]
        ans = ans + a[l] + a[r]
        r = r-i+1
        l = l+1
    print(ans)
