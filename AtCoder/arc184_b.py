ans=0
for i in range(30):
    for j in range(19):
        if 2**i*3**j <= 1e9:
            ans+=1
print(ans)

#  from sympy import isprime
#  N=100
#  for n in range(1,N+1):
    #  mark=[False]*(n+1)
    #  for i in range(1,4):
        #  if i<=n:
            #  mark[i]=True
    #  cost=1
    #  for i in range(1,n+1):
        #  if not isprime(i) or mark[i]:
            #  continue
        #  cost+=1
        #  for j in range(i,4*i,i):
            #  if j<=n:
                #  mark[j]=True
    #  for i in range(1,n+1):
        #  if mark[i]:
            #  continue
        #  cost+=1
        #  for j in range(i,4*i,i):
            #  if j<=n:
                #  mark[j]=True
    #  print(n,cost)


