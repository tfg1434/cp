eps = 1e-9
n, p = map(int, input().split())
v = [list(map(int, input().split())) for _ in range(n)]

lo = [0]*n
hi = [1]*n
ans = []
for i in range(n):
    a = v[i][1] - v[i][0]
    b = v[i][0] 
    for j in range(n):
        c = v[j][1] - v[j][0]
        d = v[j][0] 

        if a == c:
            if b < d:
                lo[i] = 1
                hi[i] = 0
                break
        elif a > c:
            lo[i] = max(lo[i], (d-b)/(a-c))
        elif a < c:
            hi[i] = min(hi[i], (d-b)/(a-c))
    
    if lo[i] < hi[i]+eps:
        ans.append(i)

print(len(ans))
ans = [x+1 for x in ans]
print(*ans)
