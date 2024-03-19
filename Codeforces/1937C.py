#!/opt/homebrew/bin/python3

def ask(a, b, c, d):
    print(f"? {a} {b} {c} {d}")
    res = input()
    if res == "<": return 0
    if res == "=": return 1
    return 2

def solve():
    n = int(input())

    # find n-1
    def find():
        vis = set()
        cur = 0
        vis.add(cur)
        mex = 0
        while mex in vis:
            mex += 1

        while mex < n:
            cmp = ask(cur, cur, mex, mex)
            assert(cmp != 1)
            if cmp == 2:
                vis.add(mex)
            else:
                vis.add(cur)
                cur = mex
                vis.add(cur)

            while mex in vis:
                mex += 1

        return cur

    a = find()
    best_b = 0
    cand = []
    for i in range(n):
        cmp = ask(a, best_b, a, i)
        if cmp == 0:
            cand = [i]
            best_b = i
        elif cmp == 1:
            cand.append(i)


    vis = set()
    cur = 0
    vis.add(cur)
    mex = 0
    while mex in vis:
        mex += 1

    while mex < len(cand):
        cmp = ask(cand[cur], cand[cur], cand[mex], cand[mex])
        assert(cmp != 1)
        if cmp == 0:
            vis.add(mex)
        else:
            vis.add(cur)
            cur = mex
            vis.add(cur)

        while mex in vis:
            mex += 1
    
    print('!', a, cand[cur])

for _ in range(int(input())):
    solve()
