def solve():
    n = int(input())
    #  if n == 1:
        #  return print("YES\nA")
    if n % 2 == 1:
        return print("NO")

    n //= 2
    ans = "AAB"*(n-1)
    ans += "AA"
    print("YES")
    print(ans)


for _ in range(int(input())):
    solve()
