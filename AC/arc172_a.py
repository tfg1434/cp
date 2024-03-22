import sys; R = input
S = lambda: map(int,R().split())

def solve():
    h, w, n = S()
    a = list(S())
    a.sort(reverse=True)
    a = [2**x for x in a]

    m = [(0, h)] # (left, height)
    for x in a:
        who = -1 # really lucky to find i didn't assign this
        mn = float('inf')
        for i, (l, h) in enumerate(m):
            if h >= x and l < mn:
                mn = l
                who = i
        
        if who == -1:
            return print("No")

        m.append((m[who][0]+x, x))
        if m[who][1] > x:
            m.append((m[who][0], m[who][1]-x))
        m.pop(who)

    #  print(m)
    print("Yes" if max(p[0] for p in m) <= w else "No")

solve()

