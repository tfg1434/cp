# I actually don't know why this doesn't work

def exclusive(A, zero, combine, node):
    n = len(A)
    exclusiveA = [zero] * n # Exclusive segment tree
 
    # Build exclusive segment tree
    for bit in range(n.bit_length())[::-1]:
        for i in range(n)[::-1]:
            # Propagate values down the segment tree    
            exclusiveA[i] = exclusiveA[i // 2]
        for i in range(n & ~(bit == 0)):
            # Fold A[i] into exclusive segment tree
            ind = (i >> bit) ^ 1
            exclusiveA[ind] = combine(exclusiveA[ind], A[i], node, i)
    return exclusiveA
 
def rerooter(graph, default, combine, finalize = lambda nodeDP,node,eind: nodeDP):
    n = len(graph)
    rootDP = [0] * n
    forwardDP = [None] * n
    reverseDP = [None] * n
 
    # Compute DP for root=0
    DP = [0] * n
    bfs = [0]
    P = [0] * n
    for node in bfs:
        for nei in graph[node]:
            if P[node] != nei:
                P[nei] = node
                bfs.append(nei)
 
    for node in reversed(bfs):
        nodeDP = default[node]
        for eind, nei in enumerate(graph[node]):
            if P[node] != nei:
                nodeDP = combine(nodeDP, DP[nei], node, eind)
        DP[node] = finalize(nodeDP, node, graph[node].index(P[node]) if node else -1)
    # DP for root=0 done
    
    # Use the exclusive function to reroot 
    for node in bfs:
        DP[P[node]] = DP[node]
        forwardDP[node] = [DP[nei] for nei in graph[node]]
        rerootDP = exclusive(forwardDP[node], default[node], combine, node)
        reverseDP[node] = [finalize(nodeDP, node, eind) for eind, nodeDP in enumerate(rerootDP)]
        rootDP[node] = finalize((combine(rerootDP[0], forwardDP[node][0], node, 0) if n > 1 else default[node]), node, -1)
        for nei, dp in zip(graph[node], reverseDP[node]):
            DP[nei] = dp
    return rootDP, forwardDP, reverseDP
 
def solve():
    n = int(input())
     
    g = [[] for _ in range(n)]
    for _ in range(n - 1):
        u,v = [int(x) - 1 for x in input().split()]
        g[u].append(v)
        g[v].append(u)
     
    default = [[0]*2 for _ in range(n)]
    # ong i wasted so much time bc i didn't return a value
    def combine(me, to, u, eind):
        me = me[:]
        if to[0]+1>me[0]:
            me[1] = me[0]
            me[0] = to[0]+1
        elif to[0]+1 > me[1]:
            me[1] = to[0]+1
        return me
        
    def finalize(me, u, eind):
        return me

    rootDP, _, _, = rerooter(g, default, combine, finalize)

    ans = float('inf')
    who = -1
    typ = -1
    for r in range(n):
        mx, tmx = rootDP[r]
        if abs(mx-tmx) > 1:
            continue

        # d is odd or d is 2 mod 4
        if mx == tmx or mx % 2 == 1:
            if mx+1 < ans:
                ans = mx+1
                who = r
                typ = 1
        # d is 0 mod 4
        else:
            if mx < ans:
                ans = mx
                who = r
                typ = 2

    print(ans)
    if typ == 1:
        for i in range(0, ans):
            print(who+1, i)
    elif typ == 2:
        assert(ans%2 == 0)
        for i in range(1, ans):
            print(who+1, i)

        par = [-1]*n
        bfs = [who]
        for u in bfs:
            for v in g[u]:
                par[v] = u
                g[v].remove(u)
            bfs += g[u]

        lo = bfs[-1]
        for _ in range(ans//2):
            lo = par[lo]
        print(lo+1, ans//2)

for _ in range(int(input())):
    solve()
