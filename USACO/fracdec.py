"""
ID: toronto4
LANG: PYTHON3
TASK: fracdec
"""
import sys
import os

if os.path.isfile("fracdec.in"):
    sys.stdin = open("fracdec.in", "r")
    sys.stdout = open("fracdec.out", "w")

def pp(s):
    for i in range(len(s)):
        if (i and i%76 == 0):
            print()
        print(s[i], end="")
    print()

def solve():
    n, d = map(int, input().split())
    ans = ""
    ans += str(n//d)
    ans += "."
    n %= d

    res = n
    t = ""
    norep = 0
    mp = {}
    for i in range(200000):
        if n in mp:
            ans += t[:mp[n]]
            t = t[mp[n]:]
            break
        if n == 0:
            norep = 1
            break

        mp[n] = i

        n *= 10
        t += str(n//d)
        n %= d

    if not t: t = "0"
    if norep:
        ans += t
    else:
        ans += f"({t})"

    pp(ans)

solve()
