#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e5+2;
int T,n,k,b[N];
vector<int>e[N];
int main(){
scanf("%d",&T);
while(T--){
scanf("%d",&n),k=0;
for(int i=1;i<=n;++i){
scanf("%d",b+i);
k=max(k,min(b[i],i));
e[b[i]].push_back(i);
}
printf("%d\n",k);
for(int x=e[0].size()?0:n+1,y;;){
y=0;
for(int i:e[x])
if(e[i].size()) y=i;
else printf("%d ",i);
if(!y) break;
printf("%d ",y);
x=y;
}
printf("\n");
for(int i=0;i<=n+1;++i) e[i].clear();
}
return 0;
}
