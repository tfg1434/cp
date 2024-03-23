import sys; R = input
S = lambda: map(int,R().split())

logn = 30


def solve():
    n, x = S()
    a = list(S())
    
    ans = -1

    for j in range(logn, -2, -1):
        if j == -1 or x & (1<<j):
            cnt = 0
            cur = 0
            last = -1
            for i in range(n):
                cur ^= a[i]
                if (j == -1 or not (cur & 1<<j)) and all((cur & (1<<jj)) == (x & (1<<jj)) for jj in range(logn, j)):
                    cur = 0
                    cnt += 1
                    last = i
            
            if last == n-1:
                ans = max(ans, cnt)

    print(ans)


for _ in range(int(input())):
    solve()

