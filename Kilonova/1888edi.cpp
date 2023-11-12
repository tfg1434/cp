/// Gheorghies Alexandru
#include<bits/stdc++.h>


using namespace std;
using str = string;



typedef long long ll;
typedef pair<ll,ll> pll;
const ll NMAX=5e5+5,MOD=1e9+7;
ll dp[NMAX],col[NMAX],prv[NMAX],ans[NMAX],p[NMAX],subtreeSize[NMAX];
vector<ll> edg[NMAX];
void dfs(ll u){
        // cout << u << '~' << p[u] << endl;
    ll formerprv=prv[col[p[u]]];
    subtreeSize[u]=1;
    prv[col[p[u]]]=u;
    for(auto it : edg[u]){
        if(it!=p[u]){
            p[it]=u;
            dfs(it);
            subtreeSize[u]+=subtreeSize[it];
        }
    }
    ll v=prv[col[u]];
    cout <<"!" << v << endl;
    if(v==1){
        // cout << col[u] << "-=" << subtreeSize[u] << endl;
         ans[col[u]]-=subtreeSize[u];
    }
    else
        dp[v]-=subtreeSize[u];
    prv[col[p[u]]]=formerprv;
    dp[u]+=subtreeSize[u];
}
void tc(){
    ll n,k;
    cin>>n>>k;

    for(ll i=1;i<=n;i++){
        dp[i]=p[i]=subtreeSize[i]=0,prv[i]=1,edg[i].clear();
        ans[i]=n;
        cin>>col[i];
    }
    for(ll i=1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    dfs(1);
    for (ll i=1 ;i <= k; i++)  cout << dp[i] <<' ';
    cout << endl;
    for(ll i=1;i<=k;i++) ans[i]*=ans[i];
    for(ll i=2;i<=n;i++){
        ans[col[p[i]]]+=dp[i]*dp[i];
    }
    for(ll i=1;i<=k;i++)
        cout<<n*n-ans[i]<<" \n"[i==k];
}
int main()
{
    // #ifndef ONLINE_JUDGE
        // freopen("in.txt","r",stdin);
        // freopen("out.txt","w",stdout);
    // #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t; cin>>t; while(t--)
        tc();
    return 0;
}
