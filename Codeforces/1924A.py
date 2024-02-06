def solve():
    n, k, m = map(int, input().split())
    s = input()

    i = 0
    ans = ""
    st = set()
    while i < m:
        st.add(s[i])
        if len(st) == k:
            st = set()
            ans += s[i]
        i += 1

    for c in list(map(chr, range(ord('a'), ord('z')+1))):
        if c not in st:
            ans += c
            break
    else:
        raise Exception("wtf")

    if len(ans) > n:
        print("YES")
    else:
        print("NO")
        while len(ans) < n:
            ans += "a"
        print(ans)





t = int(input())
for _ in range(t):
    solve()
