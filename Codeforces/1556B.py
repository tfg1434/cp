def readline():
    return map(int, input().split())

def first(a, parity):
    idx = 0
    for (i, x) in enumerate(a):
        if x == parity:
            yield abs(i - idx)
            idx += 2

def solve():
    n = int(input())
    a = [x % 2 for x in readline()]
    even = a.count(0)
    odd = a.count(1)

    if abs(even - odd) > 1:
        return -1
    
    if even > odd:
        return sum(first(a, 0))
    elif even < odd:
        return sum(first(a, 1))
    else:
        return min(sum(first(a, 0)), sum(first(a, 1)))

T = int(input())
for _ in range(T):
    print(solve())
