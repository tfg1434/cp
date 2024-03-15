import sys; R = sys.stdin.readline
S = lambda: map(int,R().split())

n,q = S()
a = [0]+[*S()]
b = [0]+[*S()]
P = 998244353
for i in range(1,n+1): a[i] += a[i-1]; b[i] += b[i-1]
rr = []
f = [1]
for i in range(1,b[n]+1): f += f[-1]*i%P,
ff = [pow(c,-1,P) for c in f]
W = pow(2,-b[n],P)%P

def C(n, r):
    return f[n]*ff[n-r]%P*ff[r]%P


p = [0]*(b[n]+1)
for i in range(b[n]+1):
    p[i] = C(b[n], i) * W % P
for i in range(b[n]-1, -1, -1):
    p[i] += p[i+1]
    p[i] %= P

# out gold - in gold, in silver, out silver
def solve(bal, sin, sout):
    #  print(f"out gold - in gold = {bal}\nsilver in = {sin}\nsilver out = {sout}")

    # offset is gold balance + silvers outside
    off = bal + sout
    if off < 0:
        return 1
    if off >= b[n]:
        return 0
    return p[off+1]

for _ in range(q):
    l,r = S()
    a1,b1 = a[r]-a[l-1],b[r]-b[l-1]
    a2,b2 = a[n]-a1,b[n]-b1
    rr += solve(a2-a1,b1,b2),

print(*rr)
