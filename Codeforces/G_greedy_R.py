def solve():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    a = list(reversed(a))

    if n == 1:
        print(1)
        return

    if a[0]-1 <= sum(a[1:]):
        print(sum(a))
    else: 
        print(2*sum(a[1:])+1)

solve()
