from functools import *
from math import *
import sys; R = input
S = lambda: map(int,R().split())

R()
n, x = S()
a = list(S())

yesno = R()
if yesno == "YES":
    a = list(S())
    g = gcd(*a[1:])
    b = list(S())
    AND = reduce(lambda x, y: x&y, b[1:])

    if g<=AND+x:
        print("wtf wrong")
        exit(-1)
else:
    for i in range(n):
        for j in range(i+1, n):
            g = gcd(a[i], a[j])

            wo = a.copy() 
            wo.pop(i)
            wo.pop(j-1)
            AND = reduce(lambda x, y: x & y, wo)
            if g > AND + x:
                print("wtf i found it")
                exit(-1)

print("ok")
