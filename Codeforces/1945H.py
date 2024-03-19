import sys; R = input
S = lambda: map(int,R().split())

def solve():
    n, x = S()
    a = list(S())
    mx = max(a)
    bits = int(log2(mx))+1

    has_bit = lambda i: {j if a[j] & (1<<i) for j in range(n)}
    
    ans = False

    # whether you can choose two numbers so that the bitwise AND is 0
    def zero():
        for i in range(bits):
            w = has_bit(i)

            if len(w) == 3:
                for take in [[0, 1], [0, 2], [1, 2]]:
                    ok = True
                    for j in range(n):
                        if j == i:
                            continue

                        W = has_bit(j)
                        W.discard(w[take[0]])
                        W.discard(w[take[1]])

                        if len(W) > 1:
                            break
                    else:
                        ok = False

                    if ok:
                        return True
            elif len(w) == 2:
                for take in [w[0], w[1]]:
                    ok = True
                    second_idx = [-1, -1]

                    for j in range(n):
                        if j == i:
                            continue

                        W = has_bit(j)
                        W.discard(take)
                        
                        if len(W) < 2:
                            continue

                        if second_idx != [-1, -1]:
                            if len(W) == 2 and second_idx[0] in W or second_idx[1] in W:
                                if second_idx[0] not in W:
                                    second_idx.remove(second_idx[0])
                                if second_idx[0] not in W:
                                    second_idx.remove(second_idx[0])
                                continue
                        else:
                            if len(W) == 2:
                                second_idx = W
                                continue
                            

                        else if len(W) >= 2:
                            ok = False
                            break

                    if ok:
                        return True
            else:
                return False

            
    if zero():
        pass


    where = [[] for _ in range(n)]
    for i, x in enumerate(a):
        where[x].append(i)

    for i, x in enumerate(a):
        for d in divisors(x)[1:]:
            if not where[d]:
                continue
            pos = where[d][0]
            if pos == i:
                if len(where[d]) < 2:
                    continue
                pos = where[d][1]

            l = min(i, pos)
            r = max(i, pos)
            AND = pre[l] & pre[]



            
