
#include<bits/stdc++.h>
using namespace std;
const int N=200000,mod=998244353;
int p[N+1],sz[N+1];
struct edge
{
    int u,v,w;
    void read(){cin>>u>>v>>w;}
    bool operator<(edge x){return w<x.w;}
}a[N+1];
int leader(int v)
{
    if(p[v]==v)return v;
    else return p[v]=leader(p[v]);
}
void unite(int u,int v)
{
    u=leader(u);
    v=leader(v);
    p[u]=v;
    sz[v]+=sz[u];
}
long long binpow(long long a,long long n)
{
    if(n==0)return 1;
    if(n%2==0)return binpow(a*a%mod,n/2);
    else return a*binpow(a,n-1)%mod;
}
#ifdef I_AM_NOOB
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__; ((cerr<<exchange(c,',')<<x),...); cerr<<endl; }(__VA_ARGS__);
#else
#define gg(...) 777771449
#endif
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,S;cin>>n>>S;
        for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
        for(int i=0;i<n-1;i++)a[i].read();
        sort(a,a+n-1);
        long long ans=1;
        for(int i=0;i<n-1;i++)
        {
            int sub_u=sz[leader(a[i].u)];
            int sub_v=sz[leader(a[i].v)];
            ans=ans*binpow(S-a[i].w+1,1ll*sub_u*sub_v-1)%mod;
            gg(S-a[i].w+1, sub_u, sub_v);
            gg(ans);
            unite(a[i].u,a[i].v);
        }
        cout<<ans<<"\n";
    }
}
