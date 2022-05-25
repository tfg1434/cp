#include <bits/stdc++.h>
constexpr int maxn = 2e5 + 5;

std::vector<int>conj[maxn];
int n,k,u,v,depth[maxn]={0},size[maxn]={0},det[maxn];
long long ans=0;
int cmp(int a,int b){return a>b;}
int dfs(int u,int f){depth[u]=depth[f]+1;size[u]=1;
	for (int i=0;i<conj[u].size();++i){
		if ((v=conj[u][i])==f)continue;
		size[u]+=dfs(v,u);
	}det[u]=size[u]-depth[u];return size[u];
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;++i){
		scanf("%d%d",&u,&v);conj[u].push_back(v);conj[v].push_back(u);
	}dfs(1,0);
	std::nth_element(det+1,det+n-k,det+n+1,cmp);
	for (int i=1;i<=n-k;++i)ans+=det[i];std::cout<<ans;
	return 0;
}

// int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    
    // ll n, k; cin >> n >> k;
    // vector<vector<ll>> adj(n+1, vector<ll>());
    // for (ll i = 0; i < n; i++) {
        // ll u, v; cin >> u >> v;
        // adj[u].push_back(v);
        // adj[v].push_back(u);
    // }

    // vector<ll> size(n+1, 0);
    // vector<ll> dist(n+1, 0);
    // vector<ll> d(n+1);

    // ll v;
    // y_combinator([&](auto rec, ll u, ll p) -> ll {
        // dist[u] = dist[p]+1;
        // size[u] = 1;
        // for (ll i = 0; i < adj[u].size(); i++) {
            // if ((v = adj[u][i]) == p) continue;

            // size[u] += rec(v, u);
        // }
        // d[u] = size[u] - dist[u];

        // return size[u];

    // })(1, 0);

    // // sort(all(d), greater<ll>());
    // //solve it in o(n) with nth_element
    // nth_element(d.begin()+1, d.begin()+n-k, d.begin()+n+1, greater<ll>());
    // ll ans = 0;
    // for (ll i = 1; i <= n-k; i++) ans += d[i];
    // cout << ans << '\n';
    
    // return 0;
// }

