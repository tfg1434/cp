def solve():
    T, G = map(int, input().split())
    n = int(input())

    p = []
    for i in range(n):
        x, y = map(int, input().split())
        p.append(x+y*1j)
    
    expected = n-2
    got = 0
    ans = list(map(int, input().split()))
    for i in range(2, n):
        a = p[ans[i-2]-1]-p[ans[i-1]-1]
        b = p[ans[i]-1]-p[ans[i-1]-1]
        if a.real*b.real+a.imag*b.imag > 0:
            got += 1

    if expected != got:
        print(f"WA expected {expected} got {got}")
        #  print(*(p[i] for i in range(n)), sep='\n')
        print(*(f"({int(p[i].real)}, {int(p[i].imag)})" for i in range(n)), sep='\n')
        print(ans)
        exit(-1)

    print("OK")     


solve()
