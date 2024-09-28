#include <bits/stdc++.h>
using namespace std;
#define int int64_t

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
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

V<V<array<int, 2>>> g;
vi h, par_edge_w;
void dfs(int u, int p, int par_edge_w) {
    ::par_edge_w[u] = par_edge_w;
    for (auto [v, w]: g[u]) if (v != p) {
        dfs(v, u, w);
        ckmax(h[u], h[v]);
    }
    h[u] += par_edge_w;
}

void solve() {
    int n; cin >> n;
    g.resize(n);
    h.resize(n);
    par_edge_w.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].pb({v, w}); g[v].pb({u, w});
    }
    dfs(0, -1, 0);
    set<array<int, 2>> q;
    for (int i = 1; i < n; i++) q.insert({h[i], i});

    int ans = 0;
    for (int k = 1; k <= n; k++) {
        if (q.size()) {
            auto [d, u] = *q.rbegin(); 
            ans += d;
            while (u != -1) {
                q.erase({h[u], u});
                int nxt = -1;
                for (auto [v, w] : g[u]) if (h[v] == h[u]-par_edge_w[u]) {
                    nxt = v;
                    break;
                }
                u = nxt;
            }
        }
        cout << 2*ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
