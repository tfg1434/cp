# 80pts
# Solves all C=2, 8x8 C=3

from random import *

n, m, C = map(int, input().split())

for _ in range(10000):
    a = [[randint(0, C-1) for _ in range(m)] for _ in range(n)]
    cost = 0
    bad_cells = []
    for i in range(n):
        for j in range(m):
            for I in range(i+1, n):
                for J in range(j+1, m):
                    if len(set([a[i][j], a[I][J], a[i][J], a[I][j]])) == 1:
                        bad_cells.extend([(i, j), (I, J), (i, J), (I, j)])
                        cost += 1
                        

    for _ in range(10000):
        if cost == 0:
            break

        r, c = choice(bad_cells)
        old_cont = 0
        for i in range(n):
            for j in range(m):
                if i == r or j == c:
                    continue
                old_cont += len(set([a[r][c], a[r][j], a[i][c], a[i][j]])) == 1
        old_val = a[r][c]
        a[r][c] = choice([x for x in range(C) if x != a[r][c]])
        new_cont = 0
        for i in range(n):
            for j in range(m):
                if i == r or j == c:
                    continue
                new_cont += len(set([a[r][c], a[r][j], a[i][c], a[i][j]])) == 1

        if new_cont >= old_cont:
            a[r][c] = old_val
        else:
            cost = cost - old_cont + new_cont
            bad_cells = []
            for i in range(n):
                for j in range(m):
                    for I in range(i+1, n):
                        for J in range(j+1, m):
                            if len(set([a[i][j], a[I][J], a[i][J], a[I][j]])) == 1:
                                bad_cells.extend([(i, j), (I, J), (i, J), (I, j)])
    
    if cost == 0:
        for i in range(n):
            print(*list(map(lambda x: int(x)+1, a[i])))
        break

