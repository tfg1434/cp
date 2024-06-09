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

V<vi> g, dp;

void calc_only_subtree(int u, int p) {
    dp[u][1] = 1;
    for (int v : g[u]) if (v != p) {
        calc_only_subtree(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

void calc_dp(int u, int p, vi super) {
    dp[u] = {max(super[0], super[1]), 1+super[0]};
    for (int v : g[u]) if (v != p) {
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }

    auto COPY = dp[u];
    for (int v : g[u]) if (v != p) {
        dp[u][0] -= max(dp[v][0], dp[v][1]);
        dp[u][1] -= dp[v][0];

        calc_dp(v, u, dp[u]);

        dp[u] = COPY;
    }
}

void solve() {
    int n; cin >> n;    
    g.assign(n, vi());
    dp.assign(n, vi(2));
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    calc_only_subtree(0, -1);
    calc_dp(0, -1, {0, 0});
    // for (int i = 0; i < n; i++) {
        // ps(i+1, dp[i]);
    // }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ckmax(ans, dp[i][0] + (g[i].size() == 1));
        // ps(i+1, dp[i][0], g[i].size() == 1);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
