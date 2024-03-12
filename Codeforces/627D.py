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

def lstTrue(lo, hi, f):
    while lo < hi:
        m = (lo+hi+1)//2
        if f(m):
            lo = m
        else:
            hi = m-1
    return lo

n, k = map(int, input().split())
a = list(map(int, input().split()))
g = [[] for _ in range(n)]
for i in range(n-1):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    g[u].append(v)
    g[v].append(u)

def check(fixed):
    #  def dfs(u, p):
        #  res = [0, 0, 1] # default
        #  for v in g[u]:
            #  if v == p:
                #  continue
            #  ret, no_ret, all_good = dfs(v, u)
            #  res[0] += ret
            #  res[1] += no_ret
            #  res[2] &= all_good

        #  # finalize
        #  if a[u] < fixed:
            #  return [0, 0, 0]
        #  if not res[2]:
            #  ret = [0, 1, 0]
            #  for son in sons:
                #  res[1] += son[0]
            #  res[1] += max(son[1] for son in sons)
            #  return res

        #  res = [1, 0, 1]
        #  for son in sons:
            #  res[0] += son[0]
        #  return res


    default = [[0, 0, 1] for _ in range(n)]
    def combine(nodeDP, neiDP, node, eind):
        me = nodeDP[:]
        me[0] += neiDP[0]
        me[1] = max(me[1], neiDP[1])
        me[2] = min(me[2], neiDP[2])
        return me
    def finalize(nodeDP, node, eind):
        if a[node] < fixed:
            return [0, 0, 0]
        if not nodeDP[2]:
            return [0, nodeDP[0]+nodeDP[1]+1, 0]
        return [nodeDP[0]+1, 0, 1]
    
    rootDP, _, _ = rerooter(g, default, combine, finalize)
    for r in range(n):
        ret, no_ret, has_bad = rootDP[r]
        #  ret, no_ret, has_bad = dfs(r, -1)
        #  print(ret, no_ret, has_bad)
        if max(ret, no_ret) >= k:
            return True

    return False

ans = lstTrue(1, 10**6+1, check)
print(ans)

