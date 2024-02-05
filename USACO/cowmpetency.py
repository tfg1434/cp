t = int(input())

def solve():
    n, q, C = map(int, input().split())

    B = [0]*(n+1)
    c = [0] + list(map(int, input().split()))
    assigned = list(map(bool, c))
    c = [1 if not score else score for score in c]

    for _ in range(q):
        l, r = map(int, input().split())
        B[l] = r;

    cur = 1
    for i in range(1, n+1):
        while cur <= i: 
            cur += 1
        while cur < B[i]:
            if B[cur] != 0 and B[cur] != B[i]:
                return print(-1)
            B[cur] = B[i]
            cur += 1

    mx_before = 0
    mx_after = 0
    i = 1
    while i <= n:
        mx_before = max(mx_before, c[i])
        mx_after = max(mx_after, c[i])
        if (B[i] == 0): 
            i += 1
            continue
        mx_after = max(mx_after, *c[i:B[i]])

        if mx_before < mx_after:
            for j in range(i, 0, -1):
                if B[j] != 0 and B[j] < B[i]:
                    return print(-1)
                if assigned[j]:
                    continue
                c[j] = mx_after
                break
            else:
                return print(-1)
            mx_before = mx_after

        if not assigned[B[i]]:
            c[B[i]] = mx_before+1

        if c[B[i]] <= mx_before:
            return print(-1)

        i = B[i]

    for i in range(1, n+1):
        if (c[i] > C):
            return print(-1)

    print(*c[1:])


for _ in range(t):
    solve()



        
