#include<bits/stdc++.h>
#define N 200005
using namespace std;
struct node{
	int sum[101];
}tree[N*4];
int a[N],n,m,x,y,l,r;
inline void pushdown(int p){
	for (int i=1;i<101;i++){
		tree[p<<1].sum[i]=tree[p].sum[tree[p<<1].sum[i]];
		tree[p<<1|1].sum[i]=tree[p].sum[tree[p<<1|1].sum[i]];
	}
	for (int i=1;i<101;i++)
		tree[p].sum[i]=i;
}
void build(int p,int l,int r){
	for (int i=1;i<101;i++)
		tree[p].sum[i]=i;
	if (l==r) return;
	int mid=(l+r) >> 1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r); 
}
void modify(int p,int l,int r,int x,int y,int from,int to){
	if (l>=x&&r<=y){
		for (int i=1;i<101;i++)
			if (tree[p].sum[i]==from)
				tree[p].sum[i]=to;
		return;
	}
	int mid=(l+r) >> 1;
	pushdown(p);
	if (x<=mid) modify(p<<1,l,mid,x,y,from,to);
	if (y>mid) modify(p<<1|1,mid+1,r,x,y,from,to); 
}
void query(int p,int l,int r){
	if (l==r){
		printf("%d ",tree[p].sum[a[l]]);
		return;
	}
	pushdown(p);
	int mid=(l+r)>> 1;
	query(p<<1,l,mid);
	query(p<<1|1,mid+1,r);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d%d",&l,&r,&x,&y);
		modify(1,1,n,l,r,x,y);
	} 
	query(1,1,n);
	return 0;
}
