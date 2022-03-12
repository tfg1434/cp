def solve():
    n = int(input())
    d = list(map(int, input().split()))
    ans = [0] * n
    
    for i in range(n, 1, -1):
        #  idx = 0
        #  for (j, x) in enumerate(d):
            #  if x == i:
                #  idx = j
                #  break
        idx = d.index(i)
        b = [0] * i
        
        for j in range(i):
            b[j-idx-1] = d[j]
        d[:i] = b[:i]
        ans[i-1] = (idx+1) % i

    print(*ans)

for _ in range(int(input())):
    solve()
