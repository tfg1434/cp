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

const int K = 450;

void solve() {
    int n, q; cin >> n >> q;
    V<array<int, 2>> record;
    while (q--) {
        int t, p; cin >> t >> p; p--;
        record.pb({t, p});
    }

    int m; cin >> m;
    V<V<array<int, 2>>> g(n), G(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb({v, i}); g[v].pb({u, i+m});
    }
    for (int U = 0; U < n; U++) if (g[U].size() > K) {
        for (auto [v, i] : g[U]) {
            G[v].pb({ U, i });
        }
    }

    V<bool> in(n), acv(2*m);
    vi shift(n), wei(2*m);
    for (auto [t, u] : record) {
        if (!in[u]) {
            // begin
            if (g[u].size() > K) {
                shift[u] -= t;
            } else {
                for (auto [v, i] : g[u]) if (in[v]) {
                    wei[i] -= t;
                }
            }

            for (auto [V, I] : G[u]) {
                acv[I] = true;
                wei[I] -= shift[V];
            }

        } else {
            // end
            if (g[u].size() > K) {
                shift[u] += t;
            } else {
                for (auto [v, i] : g[u]) if (in[v]) {
                    wei[i] += t;
                }
            }

            for (auto [V, I] : G[u]) {
                acv[I] = false;
                wei[I] += shift[V];
            }
        }

        in[u] = !in[u];
    }

    vi ans(m);
    for (int u = 0; u < n; u++) {
        for (auto [v, i] : g[u]) if (acv[i]) {
            acv[i] = false;
            wei[i] += shift[u];
        }
        for (auto [v, i] : g[u]) {
            int w = wei[i];
            if (i >= m) i -= m;
            ans[i] += w;
        }
    }
    for (int i = 0; i < m; i++) cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

