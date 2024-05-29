from random import *

n = 10# choice([1, 2, 3, 4, 5, 100, 10000])
p = 10

v = [(randint(1, p), randint(1, p)) for _ in range(n)]

print(n, p)
for a, b in v:
    print(a, b)

