from random import *
from numpy import *


n = randint(2, 20)
def fp(p):
    for i in range(n):
        if p[i] == i:
            return True
    return False

p = random.permutation(n)
while fp(p):
    p = random.permutation(n)
print(1)
print(n)
print(*list(map(lambda x: x+1, p)))

