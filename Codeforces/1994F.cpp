#include <bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#endif
 
#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
 
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }
 
const int N = 5e5, M = 5e5;
vi g[N], G[N], tour;
bool vis[N], del[M];
int dp[N], e[N], num_edges, tour_timer, edg[N];
 
int find(int u) {
    return e[u] < 0 ? u : e[u]=find(e[u]);
}
 
void unite(int u, int v) {
    if ((u=find(u)) != (v=find(v))) {
        if (e[u] > e[v]) swap(u, v);
        e[u] += e[v];
        e[v] = u;
    }
}
 
void dfs(int u) {
    vis[u] = true;
    for (int ind : g[u]) {
        int v = edg[ind]^u;
        if (vis[v]) continue;
        dfs(v);
        if (dp[v]) {
            dp[u] ^= 1;
            G[u].pb(ind); G[v].pb(ind);
            num_edges++;
        }
    }
}
 
void find_tour(int u, int p) {
    while (G[u].size()) {
        int ind = G[u].back(); G[u].pop_back();
        if (del[ind]) continue;
        int v = u^edg[ind];
        del[ind] = true;
        find_tour(v, u);
    }
    tour[tour_timer++] = u;
}
 
void solve() {
    int n, m; cin >> n >> m;    
    tour.clear();
    for (int u = 0; u < n; u++) {
        e[u] = -1;
        g[u].clear();
        G[u].clear();
        vis[u] = false;
    }
    num_edges = 0;
    for (int i = 0; i < m; i++) del[i] = false;
 
    vi a(n);
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c; u--; v--;
        edg[i] = u^v;
        if (c == 1) {
            a[u] ^= 1;
            a[v] ^= 1;
            G[u].pb(i); G[v].pb(i);
            num_edges++;
        } else {
            if (find(u) != find(v)) {
                g[u].pb(i); g[v].pb(i);
                unite(u, v);
            }
        }
    }
    for (int u = 0; u < n; u++) dp[u] = a[u];
 
    bool possible = true;
    for (int u = 0; u < n; u++) if (!vis[u]) {
        dfs(u);
        possible &= !dp[u];
    }
 
    cout << (possible ? "YES" : "NO") << '\n';
    if (possible) {
        tour_timer = 0;
        tour.resize(num_edges+1);
        find_tour(0, -1);
        cout << num_edges << '\n';
        for (int i = 0; i <= num_edges; i++) cout << tour[i]+1 << " \n"[i==num_edges];
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
