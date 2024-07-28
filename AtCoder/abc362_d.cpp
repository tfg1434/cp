#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

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
template<class T> using pqg = priority_queue<T, V<T>, greater<T>>;

void solve() {
    int n, m; cin >> n >> m;
    vi a(n); 
    for (int i = 0; i < n; i++) cin >> a[i];
    V<V<array<int, 2>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].pb({v, w}); g[v].pb({u, w});
    }
    pqg<array<int, 2>> q;
    vi dist(n, inf);
    dist[0] = a[0];
    q.push({dist[0], 0});
    while (q.size()) {
        auto [d, u] = q.top(); q.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : g[u]) if (ckmin(dist[v], d+w + a[v])) {
            q.push({dist[v], v});
        }
    }
    for (int i = 1; i < n; i++) cout << dist[i] << " \n"[i==n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
