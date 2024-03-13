import sys
input = sys.stdin.readline
 
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
 
 
n = int(input())
g = [[] for _ in range(n)]
for _ in range(n - 1):
    u,v = [int(x) - 1 for x in input().split()]
    g[u].append(v)
    g[v].append(u)


# max distance to leaf (for u)
# max length of a single path (path is in neighbours subtree)
# max product
default = [[[(0, -1), (0, -1)], [(0, -2)], 0] for _ in range(n)]
def combine(me, to, u, eind):
    dp = [None]*3
    dp[0] = me[0].copy()
    dp[1] = me[1].copy()
    dp[2] = me[2]

    dp[0].append((to[0][0][0]+1, eind))
    dp[1].append((to[0][0][0]+to[0][1][0], eind))
    return dp

def finalize(me, u, eind):
    dp = [None]*3
    dp[0] = me[0].copy()
    dp[1] = me[1].copy()
    dp[2] = me[2]

    dp[0].sort(reverse=True)
    dp[1].sort(reverse=True)
    # longest path not thru u
    dp[2] = dp[1][0][0]
    # longest path thru u
    thru = 0
    if dp[1][0][1] == dp[0][0][1]:
        thru = dp[0][1][0]+dp[0][2][0]
    elif dp[1][0][1] == dp[0][1][1]:
        thru = dp[0][0][0]+dp[0][2][0]
    else:
        thru = dp[0][0][0]+dp[0][1][0]

    dp[2] *= thru

    return dp

rootDP, forwardDP, backwardDP = rerooter(g, default, combine, finalize)
#  for r in range(n):
    #  print(rootDP[r][2])
print(max(rootDP[r][2] for r in range(n)))


        

