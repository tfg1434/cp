from random import *

n = randint(1, 10)
m = randint(1, 10)
print(n, m)
a = [[randint(0, 1) for _ in range(n)] for _ in range(m)]
for row in a:
    print(*row, sep="")

