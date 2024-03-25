import sys; R = input
S = lambda: map(int,R().split())

def solve():
    n = int(input())
    a = []
    for i in range(n):
        a.append(list(map(lambda x: int(x)-1, input().split())))

    ops = [-1]*n
    for i in range(n):
        ok = True
        for j in range(n):
            if ops[j] == -1:
                ops[j] = 6-a[i][j]
            else:
                a[i][j] += ops[j] 
                a[i][j] %= 6
                if j > 0:
                    ok &= a[i][j] == a[i][j-1]

        if not ok:
            return print("NO")

    return print("YES")

for _ in range(int(input())):
    solve()
