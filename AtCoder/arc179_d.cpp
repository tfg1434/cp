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

void precalc(int u, int p) {
    for (int v : g[u]) {
        precalc(v, u);
        sub[u] += sub[v];
        ckmax(dep[u], dep[v]+1);
    }
}

void reroot(int u, int p, const array<int, 3>& super) {
    dp[u][0] = super[0]+1;
    for (int v : g[u]) {
        reroot(v, u);
        ckmax(dp[u][0], dp[v][0]+1);
        ckmax(dp[u][1], max(dp[v][1]+1, dp[v][2]+1));
        ckmax(dp[u][2], dp[v][2]+2);
    }

    super = 
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    precalc(0, -1);
    reroot(0, -1, {0, 0, 0});
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
