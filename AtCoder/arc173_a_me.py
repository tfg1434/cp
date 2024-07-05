def solve(n):
    digits = 1
    while 9**digits < n:
        n -= 9**digits
        digits += 1

    ans = [0]*digits
    for i in range(digits):
        head = (n-1)//(9**(digits-i-1)) 
        n -= (head)*(9**(digits-i-1))

        ans[i] = head + (i == 0) + (i > 0 and head >= ans[i-1])


    return ans


for _ in range(int(input())):
    kth = int(input())
    print(*solve(kth), sep='')
