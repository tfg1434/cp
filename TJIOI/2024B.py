n, m, c = map(int, input().split())
c %= n+m
if c != 0 and c <= n:
    print("Cookie Monster")
else:
    print("Elmo")
