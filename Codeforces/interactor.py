#!/opt/homebrew/bin/python3

from math import *
from random import *
from numpy import *

n = 10
print(n)
p = random.permutation(n).tolist()
for i in range(n):
    p[i] += 1

for i in range(2*n+100):
    args = input().split()
    if args[0] == '?':
        print(lcm(p[int(args[1])-1], p[int(args[2])-1]))
    else:
        if list(map(int, args[1:])) != p:
            print(*args[1:])
            print(*p)
            raise Exception("wrong guess")
        break
else:
    raise Exception("too many guesses")

print("Okay!!")


