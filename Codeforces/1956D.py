import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

n = int(R())
a = list(S())
ans = 0

Gaps = []
for i in range(1 << n):
    res = 0
    cur = 0
    gaps = []
    for j in range(n):
        if i & (1 << j):
            res += a[j]
            if cur > 0:
                gaps.append((j-cur, j))
                cur = 0
        else:
            cur += 1
    if cur > 0:
        gaps.append((n-cur, n))
    
    for l, r in gaps:
        res += (r-l)**2
    
    if res > ans:
        ans = res
        Gaps = gaps

operations = []
def make_nn(l, r):
    # set [l, r) = 0
    for i in range(l, r):
        if not a[i]:
            continue
        operations.append((i, i+1))
        a[i] = 0

    for i in range(r-l):
        for j in range(i):
            if j == 0:
                operations.append((l, l+1))
            else:
                for k in range(j+1, 1, -1):
                    operations.append((l, l+k))
                    operations.append((l, l+1))

        operations.append((l, r))

#  a = [0, 0, 0, 0]
#  make_nn(0, 4)
#  print(operations)
#  exit(0)

#  print(Gaps)
for l, r in Gaps:
    make_nn(l, r)

print(ans, len(operations))
for l, r in operations:
    print(l+1, r)

