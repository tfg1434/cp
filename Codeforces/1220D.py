n = int(input())
a = list(map(int, input().split()))

o = list(filter(lambda x: x%2==1, a))
e = list(filter(lambda x: x%2==0, a))

if (len(o) < len(e)):
    print(len(o))
    print(*o)
else:
    print(len(e))
    print(*e)
