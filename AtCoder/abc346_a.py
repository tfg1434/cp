import sys; R = input
S = lambda: map(int,R().split())

def solve():
    n = int(input())
    a = list(S())
    for i in range(n-1):
        print(a[i]*a[i+1], end=' ')
    
solve()
