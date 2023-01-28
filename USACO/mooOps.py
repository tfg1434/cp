import sys


MOD = 1000000007

def solve():
    s = input()
    n = len(s)

    ans = 9999
    for i in range(0, n-2):
        if s[i+1] != 'O': continue
        cost = 0
        if s[i]!='M': cost+=1
        if s[i+2]!='O': cost+=1
        ans = min(ans, cost)

    if (ans == 9999):
        print(-1)
        return
    print(n-3+ans)

t = int(input())
for _ in range(t):
    solve()

