from random import *
MAX = 10
print(MAX**4)
for p in range(MAX):
    for q in range(MAX):
        for x in range(MAX):
            for y in range(MAX):
                print(p, q, x, y)
