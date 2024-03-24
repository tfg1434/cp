import sys; R = input
S = lambda: map(int,R().split())

s = "wbwbwwbwbwbw"
n = 12
def solve():
    w, b = S()   

    ok = False
    for i in range(n):
        W = w
        B = b
        j = i
        while W > 0 or B > 0:
            if s[j] == 'w':
                W -= 1
            else:
                B -= 1
            j = (j+1)%n

        ok |= W == 0 and B ==0

    print("Yes" if ok else "No")


solve()
