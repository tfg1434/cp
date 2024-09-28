import numpy as np
s = ""
N = 10
for i in range(1, 11):
    s=s+"0"+"".join('0' if c=='1' else '1' for c in s[::-1])
    a=np.array(list(s))
    ones=np.where(a=='1')[0]
    gaps=np.array([])
    for j in range(len(ones)-1):
        gaps=np.append(gaps,ones[j+1]-ones[j])
    print(s)
    print(ones)
    print(gaps)
