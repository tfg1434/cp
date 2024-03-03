import random

n = 7
k = random.randint(1, n)

print(n, k)

b = []
for i in range(n):
    a = [random.choice([1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3]) for _ in range(n)]
    if b:
        for j in range(n):
            if b[j] == 2 and a[j] == 2:
                a[j] = 1

    print(*a)

    b = a.copy()

