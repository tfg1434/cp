def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    
    ok = True
    reserve = [0]*(n+1)
    i,j = n-1,n-1
    while j >= 0:
        while j > 0 and b[j] == b[j-1]:
            reserve[b[j]] += 1
            j -= 1

        if a[i] == b[j]:
            i -= 1
            j -= 1
        else:
            if not reserve[a[i]]:
                ok = False
                break
            reserve[a[i]] -= 1
            i -= 1

    return ok



t = int(input())
for _ in range(t):
    print("YES" if solve() else "NO")

