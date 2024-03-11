def solve():
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort()
    b.sort()
    
    ans = 0
    for i in range(n):
        j = 0
        while j < m and a[i]+b[j] <= k:
            j += 1
        ans += j

    print(ans)



for _ in range(int(input())):
    solve()
