import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    n, L = S()
    ab = []
    for i in range(n):
        x, y = S()
        ab.append([x, y])
    ab.sort(key=lambda x:x[1])
    
    def check(k):
        if k == 0:
            return True
        if k == 1:
            pass

        for i in range(n):
            mx = ab[i][0]
            tot = mx
            cnt = 1
            for j in range(i+1, n):
                if cnt < k-2:
                    mx = max(mx, ab[j][0])
                    cnt += 1
                else:
                    if ab[j][0] >= mx:
                        continue
                    
                if ab[j][0] > mx:
                    tot 



for _ in range(int(R())):
    solve()
