import sys


MOD = 1000000007

def no():
    print("NO")

def solve():
    n = int(input())
    s = input()

    ts = []
    ms = []
    for i in range(n):
        if s[i] == 'M':
            ms.append(i)
        else:
            ts.append(i)
    if len(ts) != len(ms) * 2:
        no()
        return
    for (i, m) in enumerate(ms):
        if m < ts[i] or m > ts[i + len(ms)]:
            no()
            return

    print("YES")

for _ in range(int(input())):
    solve()

