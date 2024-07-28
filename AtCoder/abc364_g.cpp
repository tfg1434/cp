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

// #pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#define pct __builtin_popcountll
constexpr int p2(int x) { return (int)1 << x; }

void solve() {
    int n, m, k; cin >> n >> m >> k; k--;
    vector g(n, V<array<int, 2>>()); // put(n) in the innermost brackets :(((
    while (m--) {
        int u, v, c; cin >> u >> v >> c; u--; v--;
        g[u].pb({v, c}); g[v].pb({u, c});
    }

    vector dp(p2(k), vi(n, inf));
    for (int u = 0; u < k; u++) {
        dp[p2(u)][u] = 0;
    }

    for (int msk = 1; msk < p2(k); msk++) {
        for (int u = 0; u < n; u++) {
            for (int sub = (msk-1)&msk; sub > 0; sub = (sub-1)&msk) {
            // for (int sub = msk; sub > 0; sub = (sub-1)&msk) {
                ckmin(dp[msk][u], dp[sub][u]+dp[msk^sub][u]);
            }
        }

        pqg<array<int, 2>> q;
        for (int u = 0; u < n; u++) {
            q.push({dp[msk][u], u});
        }
        while (q.size()) {
            auto [d, u] = q.top(); q.pop();
            if (d != dp[msk][u]) continue;
            for (auto [v, w] : g[u]) if (ckmin(dp[msk][v], d+w)) {
                q.push({ dp[msk][v], v });
            }
        }
    }

    for (int i = k; i < n; i++) {
        cout << dp[p2(k)-1][i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
