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

int n, m, k, s, t;
V<V<array<int, 2>>> g;
vi dist[2];

void calc_dist(int u, int p, int i) {
    for (auto [v, w] : g[u]) if (v != p) {
        dist[i][v] = dist[i][u]+w;
        calc_dist(v, u, i);
    }
}

void solve() {
    cin >> n >> m >> k >> s >> t; s--; t--;
    g.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].pb({v, w}); g[v].pb({u, w});
    }
    for (int i = 0; i < 2; i++) {
        dist[i].resize(n);
    }
    calc_dist(s, -1, 0);
    calc_dist(t, -1, 1);
    auto sorted_t_dists = dist[1]; sort(all(sorted_t_dists));

    // it's harder to achieve higher min_cost
    // it's easier to achieve smaller min_cost
    int lo = 0, hi = inf;
    while (hi-lo > 1) {
        int min_cost = (lo+hi)/2; // the min cost which i will allow
        int cancellations = 0;
        for (int u = 0; u < n; u++) {
            // if s_dist[u]+k+sorted_t_dists[i] < min_cost, then cancel the i-th teleport from u.
            // sorted_t_dists[i] < min_cost-s_dist[u]-k
            int cnt = upb(sorted_t_dists, min_cost-dist[0][u]-k-1);
            for (auto [v, w] : g[u]) {
                if (dist[0][u]+k+dist[1][v] < min_cost) {
                    cnt--;
                }
            }
            cancellations += cnt;
        }

        // ps("we can make the cost at least", min_cost, "by cancelling teleports");
        (cancellations <= m && dist[0][t] >= min_cost) ? lo = min_cost : hi = min_cost;
    }

    ckmin(lo, (int)1e9);
    cout << lo << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
