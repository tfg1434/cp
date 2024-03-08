from random import *

n = 6
print(0, 0)
print(n)

max_x = 9

for _ in range(n):
    print(randint(-max_x, max_x), randint(-max_x, max_x))
