import sys


MOD = 1000000007

def solve():
    n = int(input())
    s = input()
    s = " " + s
    yes, no = 0, 0
    for (i, c) in enumerate(s):
        if c == "G":
            if i % 2 == 00:
                yes += 1
            else:
                no += 1



solve()

