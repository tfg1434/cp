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

const int N = 5e4;
vi dp[N], g[N];
int ans, k;

void tree_dp(int u, int p) {
    dp[u] = {1};
    for (int v : g[u]) if (v != p) {
        tree_dp(v, u);
        dp[v].pb(0);
        if (dp[v].size() > dp[u].size())
            swap(dp[v], dp[u]);
        for (int i = 0; i <= k; i++) if (i < dp[u].size() &&
                k-i < dp[v].size()){
            ans += dp[u][dp[u].size()-1 - i]*dp[v][dp[v].size()-1 - (k-i)];
        }
        for (int i = 0; i < dp[v].size(); i++) {
            dp[u][dp[u].size()-1 - i] += dp[v][dp[v].size()-1 - i];
        }
    }
}

void solve() {
    int n; cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    tree_dp(0, -1);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
