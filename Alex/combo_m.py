import sys; R = input
S = lambda: map(int,R().split())

P = 10**9+7
mx_n = 10**6
f = [1]
for i in range(1, mx_n+1):
    f.append(f[-1]*i%P)
ff = [pow(f[i], P-2, P) for i in range(mx_n+1)]
def C(n, r):
    return f[n]*ff[n-r]%P*ff[r]%P
p3 = [1]
for i in range(1, mx_n+1):
    p3.append(p3[-1]*3%P)

def solve():
    n, k = S()

    if k == 0:
        return print(p3[n])

    ans = 0
    for i in range(1, k+1):
        groups = C(k-1, i-1)
        if n-k-i >= 0:
            spacers = C(n-k-i + i, i)
            ans = (ans + groups*spacers%P*p3[k-i]%P*p3[n-k-i]%P) % P
        if n-k-i+1 >= 0:
            spacers = C(n-k-i+1 + i-1, i-1)
            ans = (ans + groups*spacers%P*p3[k-i]%P*p3[n-k-i+1]%P) % P

    print(ans)


solve()


