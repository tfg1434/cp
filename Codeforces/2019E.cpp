#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define len(x) (int)((x).size())
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }
#define pct __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
constexpr int p2(int x) { return (int)1 << x; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-clz(x); } // floor(log2(x)) 

V<vi>g;
vi dep,max_dep,pre_max_dep,suf_dep;
void dfs(int u,int p){
    for(int v:g[u])if(v!=p){
        dep[v]=max_dep[v]=dep[u]+1;
        dfs(v,u);
        ckmax(max_dep[u],max_dep[v]);
    }
    pre_max_dep[max_dep[u]+1]++;
    suf_dep[dep[u]]++;
}

void solve() {
    int n;cin>>n;
    g.assign(n,vi());
    dep.assign(n,0);
    max_dep.assign(n,0);
    pre_max_dep.assign(n+1,0);
    suf_dep.assign(n+1,0);

    for (int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;u--;v--;
        g[u].pb(v);g[v].pb(u);
    }
    dfs(0,-1);
    // for(int i=1;i<=n;i++){
        // ps(i-1,pre_max_dep[i]);
    // }
    for(int i=0;i<n;i++)pre_max_dep[i+1]+=pre_max_dep[i];
    for(int i=n-1;i>0;i--)suf_dep[i-1]+=suf_dep[i];
    int ans=n;
    for(int k=0;k<n;k++){
        int cost=pre_max_dep[k]+suf_dep[k+1];
        ckmin(ans,cost);
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
