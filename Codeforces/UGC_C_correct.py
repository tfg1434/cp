import math

def solve():
    n, k = map(int, input().split())
    a = [list(map(int, input().split())) for _ in range(n)]

    ans = 0
    for i in range(n-1):
        # [left, right), indices of wells
        wells = [[float('inf'), float('inf'), []]]
        for j in range(n):
            if 3 in {a[i][j], a[i+1][j]}:
                wells[-1][1] = min(wells[-1][1], j)
                wells.append([float('inf'), float('inf'), []])
                continue

            wells[-1][0] = min(wells[-1][0], j)
            if 2 in {a[i][j], a[i+1][j]}:
                wells[-1][2].append((j, a[i][j] == 2))

        if math.isinf(wells[-1][1]):
            wells[-1][1] = n

        #  print(wells)
        dbg = 0
        # [world_l, world_r)
        for world_l, world_r, WELLS in wells:
            if not WELLS:
                continue

            r = -float('inf')
            possible = 0
            prev_w = world_l - 1
            prev_updown = -1

            for w, updown in WELLS:
                # how far left we can go using current well, exclusive
                p = w-1
                while p > prev_w and (a[i][p] == 1 and a[i+1][p] == 1) and w-p < k:
                    p -= 1

                # how far right we can go using current well, exclusive
                R = w+1
                while R < world_r and (a[i][R] == 1 and a[i+1][R] == 1) and R-w < k:
                    R += 1
                mult = R-w

                x = w-p

                if p < r + (prev_updown != -1 and updown!=prev_updown):
                    x += possible

                #  print("Contribution", mult*x)
                dbg += mult*x
                prev_w = w
                prev_updown = updown
                r = R
                possible = x

        #  print(dbg)
        ans += dbg

    print(ans)


solve()
