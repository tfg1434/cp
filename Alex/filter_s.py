# same as .cpp, idk why this TLEs

import io, sys; R = lambda f=io.StringIO(sys.stdin.buffer.read().decode()).readline: f().rstrip() 
S = lambda: map(int,R().split())

def solve():
    a, b, c, d = S()
    s = R()
    A = sum(1 if x == 'A' else 0 for x in s)
    B = len(s) - A
    if a+c+d != A:
        return print("NO")
    if b+c+d != B:
        return print("NO")

    blocks = []
    cur = ""
    for i, x in enumerate(s):
        if cur and x == cur[-1]:
            blocks.append(cur)
            cur = x
        else:
            cur += x
    blocks.append(cur)
            
    either = 0
    ab_blocks = []
    ba_blocks = []
    for block in blocks:
        if len(block) < 2:
            continue
        if len(block) % 2:
            either += len(block)//2
            continue

        if block[:2] == "AB":
            ab_blocks.append(len(block)//2)
        else:
            ba_blocks.append(len(block)//2)
    ab_blocks.sort()
    ba_blocks.sort()

    if sum(ab_blocks) <= c and sum(ba_blocks) <= d:
        return print("YES") if either >= c-sum(ab_blocks) + d-sum(ba_blocks) else print("NO")

    if sum(ab_blocks) >= c:
        ab_blocks, ba_blocks = ba_blocks, ab_blocks
        c, d = d, c

    if sum(ab_blocks) >= c:
        return print("YES")

    ab_sum = sum(ab_blocks)
    ba_extra = sum(ba_blocks) - d

    while ba_extra > 1:
        if ba_blocks[-1] <= ba_extra:
            ab_sum += ba_blocks[-1]-1
            ba_extra -= ba_blocks[-1]
            ba_blocks.pop()
        else:
            ab_sum += ba_extra - 1
            break

    if either >= max(0, c-ab_sum):
        print("YES")
    else:
        print("NO")





for _ in range(int(R())):
    solve()
