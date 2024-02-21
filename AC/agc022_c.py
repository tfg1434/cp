def solve(n):
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    bad = set()
    def dfs(u, dest):
        if u == dest:
            return True

        for m in range(1, u+1):
            if m in bad:
                continue
            if dfs(u%m, dest):
                return True
        return False

    for i in range(50, 0, -1):
        bad.add(i)
        ok = True
        for j in range(n):
            ok &= dfs(a[j], b[j])

        if not ok:
            bad.remove(i)

    exists = True;
    for j in range(n):
        exists &= dfs(a[j], b[j])
    if not exists:
        return print(-1)

    cost = 0
    for i in range(1, 51):
        if i not in bad:
            cost += 2**i

    print(cost)

n = input()
solve(int(n))
#  while True:
    #  n = input()
    #  if not n:
        #  break
    #  solve(int(n))
            
