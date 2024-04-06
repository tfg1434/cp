import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n = int(R())
    a = list(S())

    pre = [0]*(n+1)
    mex = 0
    st = set()
    for i in range(n):
        st.add(a[i])
        while mex in st:
            mex += 1
        pre[i+1] = mex

    suf = [0]*n
    mex = 0
    st = set()
    for i in range(n-1, -1, -1):
        st.add(a[i])
        while mex in st:
            mex += 1
        suf[i] = mex

    idx = -1
    for i in range(1, n): # first i chars in prefix
        if pre[i] == suf[i]:
            idx = i

    if idx == -1:
        print(-1)
    else:
        print(2)
        print(1, idx)
        print(idx+1, n)


for _ in range(int(R())):
    solve()



