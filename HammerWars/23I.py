import math
import sys; R = input
S = lambda: map(int,R().split())

def solve():
    n, x = S()
    if x == 0:
        return print(-1)
    if n == 1:
        return print(-1)

    logn = int(math.log10(n))
    ten = 10**logn
    a = (n+3)//4
    b = (3*n+19)//20

    if x // ten == 1:
        ans = [x]*n
        j = 0
        for i in range(b):
            a[j] = 2*ten
            a[j+1] = 2*x - a[j]
            j += 2

        if n == 2 and a[1]//ten != 1:
            return print(-1)
        return print(*ans)

    if x // ten == 2:
        ans = [x]*n
        j = 0
        for i in range(a):
            a[j] = 2*ten-1
            a[j+1] = 2*x-a[j]
            j += 2

        if n == 2 and a[1]//ten != 2:
            return print(-1)
        return print(*ans)

    if 3 <= x <= 9:
        ans = [2]*b
        cur = 2*b
        cnt1 = 0
        ans += 
        for i in range(a):



        if len(ans) > n:
            return print(-1)
        return print(*ans)

    # starts with 3_, 4_, ..., 9_
    if n < a+b:
        return print(-1)
    ans = [19]*a + [29]*b
    num = n*x - 19*a - 29*b
    den = n-a-b
    if (num+den-1)//den > 2*x:
        return print(-1)

    for i in range(num%den):
        ans.append((num+den-1)//den)
    for i in range(n-a-b - num%den):
        ans.append(num//den)
    
    return print(*ans)

solve()



    
