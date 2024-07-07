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

V<V<array<int, 2>>> g;
int max_dist, furthest_node;

void find_furthest(int v, int p, int dist=0) {
    if (ckmax(max_dist, dist)) {
        furthest_node = v;
    }
    for (auto [to, w] : g[v]) if (to != p) {
        find_furthest(to, v, dist+w);
    }
}

void solve() {
    int n; cin >> n;
    g.resize(n);
    int W = 0;
    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].pb({v, w}); g[v].pb({u, w});
        W += w;
    }

    find_furthest(0, -1);
    int a = furthest_node;
    max_dist = 0;
    find_furthest(a, -1);

    cout << 2*W - max_dist << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
