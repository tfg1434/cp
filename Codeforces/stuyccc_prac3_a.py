# choke

def solve():
    n, q = map(int, input().split())
    e = list(map(int, input().split()))

    for _ in range(q):
        i, j = map(int, input().split())
        i -= 1
        j -= 1
        if i > j:
            i, j = j, i

        print("yes" if i+1 >= j or max(e[i+1:j]) < max(e[i], e[j]) else "no")

solve()
