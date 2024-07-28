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

V<vi> g;
vi par, leaves, deg;
void dfs(int u, int p) {
    par[u] = p;
    bool is_leaf = true;
    for (int v : g[u]) if (v != p) {
        is_leaf = false;
        dfs(v, u);
    }
    if (is_leaf) leaves.pb(u);
}

void solve() {
    int n; cin >> n;
    g.resize(n);
    par.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    dfs(0, -1);
    deg.resize(n);
    for (int i = 0; i < n; i++) deg[i] = g[i].size();
    V<array<int, 2>> ans(n/2+1);
    int root = 0;
    for (int i = 0; i < n/2; i++) {
        if (leaves.size() == 1) {
            ans[i] = {root, leaves[0]};
            root = g[root][0];
            leaves[0] = par[leaves[0]];
        } else {
            int u = end(leaves)[-1], v = end(leaves)[-2];
            leaves.pop_back(); leaves.pop_back();
            ans[i] = {u, v};
            if (--deg[par[u]] == 1) leaves.pb(par[u]);
            if (--deg[par[v]] == 1) leaves.pb(par[v]);
        }
    }
    for (int i = 0; i < n/2; i++) cout << ans[i][0]+1 << ' ' << ans[i][1]+1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
