for _ in range(int(input())):
    n, m = map(int, input().split())
    ans = n%2 == m%2 and n >= m
    print("YES" if ans else "NO")
