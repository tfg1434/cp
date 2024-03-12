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



n, m = map(int, input().split())
g = [[] for _ in range(n)]
for i in range(n-1):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)

cnt = [0]*n
for u in map(int, input().split()):
    cnt[u-1] = 1

#  def returning(u, p):
    #  res = cnt[u]
    #  for v in g[u]:
        #  if v != p:
            #  x = returning(v, u)
            #  if x > 0:
                #  res += x+2
    #  return res

#  ans = returning(0, -1)

#  def maxrootdist(u, p):
    #  res = 0
    #  for v in g[u]:
        #  if v != p:
            #  res = max(res, maxrootdist(v, u)+1)
    #  return res

#  ans -= maxrootdist(0, -1)

def one():
    default = cnt
    def combine(nodeDP, neiDP, node, eind):
        return nodeDP + neiDP + (2 if neiDP > 0 else 0)
    def finalize(nodeDP, node, eind):
        return nodeDP
    rootDP, forwardDP, reverseDP = rerooter(g, default, combine, finalize)
    return rootDP

def two():
    default = [-float('inf')]*n
    for i in range(n):
        if cnt[i]:
            default[i] = 0

    def combine(nodeDP, neiDP, node, eind):
        return max(nodeDP, neiDP+1)
    def finalize(nodeDP, node, eind):
        return nodeDP
    rootDP, forwardDP, reverseDP = rerooter(g, default, combine, finalize)
    return rootDP

uno = one()
dos = two()
#  print(*uno)
#  print(*dos)

sol = -1
ans = float('inf')
for i in range(n):
    cand = uno[i]-dos[i]
    if cand < ans:
        ans = cand
        sol = i

print(sol+1) # 0-index
print(ans-m) # i marked cnt with 1, undo it


