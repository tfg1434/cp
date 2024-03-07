import random

n = 8
a = [random.randint(0, 1) for _ in range(n)]

m = random.randint(1, n)
b = []
for i in range(m-1):
    b.append(random.randint(1, n-(m-1-i) - sum(b)))
b.append(n-sum(b))

print(n, m)
print(*a)
print(*b)

