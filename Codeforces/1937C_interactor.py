#!/opt/homebrew/bin/python3
from math import *
from random import *
import numpy as np

print(1)
n = 10000
mx = (1<<int(log2(n)+1))-1
#  print(n, mx)
#  exit()
print(n)
p = np.random.permutation(n).tolist()

for i in range(3*n):
    args = input().split()
    if args[0] == '?':
        a = p[int(args[1])]|p[int(args[2])]
        b = p[int(args[3])]|p[int(args[4])]
        if a == b: print("=")
        if a < b: print("<")
        if a > b: print(">")
    else:
        if mx != p[int(args[1])]^p[int(args[2])]:
            print(*args[1:])
            print(*p)
            raise Exception("wrong guess")
        break
else:
    raise Exception("too many guesses")

print("Okay!!")


