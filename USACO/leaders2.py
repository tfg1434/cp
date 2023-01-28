n = int(input())
breeds = input()
e = list(map(int, input().split()))

counter = 0

for i in range(n):
    for j in range(i+1, n):
        if i+1 <= e[i] and e[j] <= j+1 and (breeds[i] != breeds[j] or breeds[j] in breeds[i+1:e[i]+1]):
            counter += 1

print(counter)

