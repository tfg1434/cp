import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

from collections import Counter

P = 10**9+7
max_n = 2*10**5
f = [1]
for i in range(1, max_n+1):
    f.append(f[-1]*i%P)

n, m = S()
a = Counter(list(S()))
b = Counter(list(S()))
keys = set(a.keys()).union(b.keys())
inter = {k : max(a.get(k, -float('inf')), b.get(k, -float('inf'))) for k in keys }
inter = dict((u, v) for u, v in inter.items() if v > 0)

ans = f[sum(v for v in inter.values())]
for u, v in inter.items():
    ans = (ans*pow(f[v], P-2, P)) % P

print(ans)



