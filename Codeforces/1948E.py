def solve():
    n, k = map(int, input().split())
    if k > n:
        k = n
    num = (n+k-1)//k
    rem = n%k

    line1 = []
    line3 = []
    
    for i in range(num):
        arr = []
        if len(line1)+k > n:
            kk = n-len(line1)

            for j in range(kk):
                arr.append(j+1+kk//2)
                if arr[-1] > kk:
                    arr[-1] -= kk
        else:
            for j in range(k):
                arr.append(j+1+k//2)
                if arr[-1] > k:
                    arr[-1] -= k
        
        #  print(arr)
        arr = [x+i*k for x in arr]
        #  print(arr)
        line1 += arr

    for i in range(n):
        line3.append(i//k + 1)

    print(*line1)
    print(num)
    print(*line3)

for _ in range(int(input())):
    solve()
