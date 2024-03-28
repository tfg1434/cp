from collections import Counter
import io, sys; R =lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

P = 998244353
mx_n = 3*10**5
f = [1]
for i in range(1, mx_n+1):
    f.append(f[-1]*i%P)

def solve():
    n = int(R())
    a = []
    for _ in range(n):
        x, y = S()
        a.append((x, y))

    def count(z):
        r = 1
        i = 0
        while i < len(z):
            j = i + 1
            while j < len(z) and z[i] == z[j]:
                j += 1
            r = r * f[j - i] % P
            i = j
        return r

    ans = f[n]
    for i in range(2):
        #  tmp = sorted([x[i] for x in a])
        #  ans -= count(tmp)
        c = Counter(x[i] for x in a)
        res = 1
        for u, v in c.most_common():
            res *= f[v]
            res %= P
        ans -= res

    a.sort()
    is_sorted = all(a[i][0] <= a[i+1][0] and a[i][1] <= a[i+1][1] for i in range(n-1))
    if is_sorted:
        both = 1
        #  i = 0
        #  while i < len(a):
            #  j = i + 1
            #  while j < len(a) and a[i] == a[j]:
                #  j += 1
            #  both *= f[j - i] 
            #  both %= P
            #  i = j

        cur = 1
        for i in range(1, n+1):
            if i < n and a[i] == a[i-1]:
                cur += 1
            else:
                both *= f[cur] # IT COST ME SO MUCH TIME
                both %= P
                cur = 1
        ans += both

    print(ans % P)

solve()


