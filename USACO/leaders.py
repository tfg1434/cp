import sys


MOD = 1000000007

def solve():
    n = int(input())
    s = input()
    e = [int(x) for x in input().split()]
    h, g = [], []
    lh, rh, lg, rg = s.find('H'), s.rfind('H'), s.find('G'), s.rfind('G')

    for i in range(n):
        if s[i] == 'G':
            if i <= lg and i+e[i] >=rg:
                g.append(i)
        if s[i] == 'H':
            if i <= lh and i+e[i] >=rh:
                h.append(i)

    ans1 = 0
    ans2 = set()
    for i, x in enumerate(h):
        ans1+=len(h)-1
        for j in range(x):
            if (s[j] == 'H'): continue
            if (j + e[j] >= x): 
                ans2.add((j, x))
                #  print("found")
    for i, x in enumerate(g):
        ans1+=len(g)-1
        for j in range(x):
            if (s[j] == 'G'): continue
            if (j + e[j] >= x): 
                ans2.add((x, j))

    print(ans1+len(ans2))

solve()

