import sys; R = input
S = lambda: map(int,R().split())

def solve():
    n, k, s = S()
    ans = (k+s-1)//s
    for _ in range(n):
        pos, spd = S()
        ans = max(ans, (k-pos+spd-1)//spd)

    print(ans)

for _ in range(int(input())):
    solve()

