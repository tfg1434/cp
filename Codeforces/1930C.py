from collections import Counter

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n):
        a[i] += i+1
    counter = Counter(a)

    cur = 0
    a = list(set(a))
    a.sort(reverse=True)
    cnt = n-len(a)
    ans = []
    for i in range(len(a)):
        if i > 0:
            adv = min(a[i-1]-a[i]-1, cnt, cur)
            for j in range(adv):
                ans.append(a[i-1]-j-1)
            cnt -= adv
            cur -= adv
        ans.append(a[i])
        counter[a[i]] -= 1
        cur += counter[a[i]]

    for _ in range(cnt):
        ans.append(ans[-1]-1)

    print(*ans)


t = int(input())
for _ in range(t):
    solve()
