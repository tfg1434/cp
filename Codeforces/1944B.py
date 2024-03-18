from collections import Counter

def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    c1 = Counter(a[:n])
    c2 = Counter(a[n:])
    w = []
    z = []

    i = 0
    arr = c1.most_common()
    while len(w) < 2*k:
        if arr[i][1] == 2:
            w.extend(arr[i][0] for _ in range(2))
        else:
            w.append(arr[i][0])
            z.append(arr[i][0])
        i += 1
    
    arr = c2.most_common()
    i = 0
    while len(z) < len(w):
        if arr[i][1] == 2:
            z.extend(arr[i][0] for _ in range(2))
        i += 1

    print(*w)
    print(*z)

for _ in range(int(input())):
    solve()
