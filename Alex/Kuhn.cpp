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
vi match;
V<bool> vis;

bool kuhn(int v) {
    vis[v] = true;
    for (int to : g[v]) {
        if (match[to] == -1 || !vis[match[to]] && kuhn(match[to])) {
            match[to] = v;
            return true;
        }
    }
    return false;
}

void solve() {
    int n, m, edges; cin >> n >> m >> edges;
    g.resize(n);
    match.resize(n, -1);
    for (int i = 0; i < edges; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v);
    }
    for (int i = 0; i < n; i++) {
        vis.assign(n, false);
        kuhn(i);
    }
    for (int i = 0; i < m; i++) {
        cout << match[i]+1 << ' ' << i+1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
