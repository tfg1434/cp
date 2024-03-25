import sys; R = input
S = lambda: map(int,R().split())

def solve():
    _ = R()
    a = list(S())
    ans = 0
    for x in a:
        ans += (x+1)//2

    print(ans)

for _ in range(int(input())):
    solve()

