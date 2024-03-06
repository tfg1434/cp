# subtask O(N^2)
# see moochanics.cpp for full solve

def solve():
    n = int(input())
    p = list(map(int, input().split()))
    s = list(map(int, input().split()))
    ind = [i for i in range(n)]

    ans = [0]*n
    for _ in range(n//2):
        T = float('inf')
        pos = -1

        for i in range(n-1):
            t = -1
            if i % 2 == 0:
                tmp = 2*((p[i+1]-p[i] + s[i]+s[i+1]-1) // (s[i]+s[i+1])) - 1
                t = max(1, tmp)
            else:
                tmp = 2*((p[i+1]-p[i] + s[i]+s[i+1]-1) // (s[i]+s[i+1]))
                t = max(2, tmp)

            if (t < T):
                T = t 
                pos = i

        n -= 2
        ans[ind[pos]] = T
        ans[ind[pos+1]] = T

        p = p[:pos] + p[pos+2:]
        s = s[:pos] + s[pos+2:]
        ind = ind[:pos] + ind[pos+2:]
        
    print(*ans)


for _ in range(int(input())):
    solve()

