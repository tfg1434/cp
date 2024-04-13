import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    x = list(map(int, R()))
    y = list(map(int, R()))

    a = []
    b = []
    dif = False
    for i in range(len(x)):
        if x[i] != y[i]:
            if not dif:
                a.append(max(x[i], y[i]))
                b.append(min(x[i], y[i]))
            else:
                a.append(min(x[i], y[i]))
                b.append(max(x[i], y[i]))

            dif = True
        else:
            a.append(x[i])
            b.append(x[i])

    print(*a, sep="")
    print(*b, sep="")

for _ in range(int(R())):
    solve()
