m = 10**9+7
fact = [1]
inv = []
n,k = map(int,input().split())
for i in range(1,n+1):
  fact.append((fact[-1]*i)%m)
inv.append(pow(fact[-1],m-2,m))
for i in range(n,0,-1):
  inv.append((inv[-1]*i)%m)
inv.reverse()

def C(n, r):
    return fact[n]*inv[n-r]%P*inv[r]%P

ans = 0
for i in range(min(k,n-k+1)):
    ans += C(k-1, i)*p3[n-2-2*i]*(n-k)*(2*i-k+n+3)
  ans += fact[k-1]*inv[i]*inv[k-1-i]*pow(3,n-2-2*i,m)*(n-k)*(2*i-k+n+3)*fact[n-k-1]*inv[i+1]*inv[n-k-i]
  ans %= m
if k == 0:
    print(pow(3,n,m))
elif k == n:
    print(pow(3,n-1,m))
else:
    print(ans)
