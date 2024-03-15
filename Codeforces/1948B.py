def solve():
    n = int(input())
    a = list(map(int, input().split()))
    idx = n-1
    while idx > 0 and a[idx-1] <= a[idx]:
        idx -= 1

    b = [str(x) for x in a[:idx]]
    cs = []
    for t in b:
        for c in t:
            cs.append(int(c))

    check = cs+a[idx:]
    ok = True
    for i in range(len(check)-1):
        if check[i] > check[i+1]:
            ok = False

    print("YES" if ok else "NO")



for _ in range(int(input())):
    solve()
