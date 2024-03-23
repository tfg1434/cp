import sys; R = input
S = lambda: map(int,R().split())

def solve():
    n = int(input())
    a = list(S())
    a.sort()

    mid = (n-1)//2
    idx = mid
    while idx<n and a[idx] == a[mid]:
        idx += 1

    print(idx-mid)

for _ in range(int(input())):
    solve()


