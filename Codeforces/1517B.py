def solve():
    n, m = (int(x) for x in input().split())
    b = [sorted([int(x) for x in input().split()]) for _ in range(n)]
    ans = [[] for _ in range(n)]
    
    for i in range(m):
        mn = min(range(n), key=lambda x: b[x][0])
        for j in range(len(b)):
            if j == mn: ans[j].append(b[j].pop(0))
            else: ans[j].append(b[j].pop())

    for row in ans:
        for col in row:
            print(col, end=' ')
        print()

for _ in range(int(input())):
    solve()
