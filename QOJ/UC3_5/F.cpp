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

int n;
V<V<array<int, 2>>> g;
vi dist;

void dij(int u) {
    dist.assign(n+1, inf);
    pqg<array<int, 2>> q;
    dist[n] = 0;
    q.push({dist[n], n});
    while (q.size()) {
        auto [d, u] = q.top(); q.pop();
        if (d != dist[u]) continue;
        for (auto [w, v] : g[u]) if (ckmin(dist[v], dist[u]+w)) {
            q.push({dist[v], v});
        }
    }
}

void solve() {
    cin >> n;
    g.resize(n+1);
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    V<vi> dp(n, vi(n+1, inf));
    for (int i = 0; i < n; i++) dp[i][i+1] = 0;

    for (int len = 2; len <= n; len++) {
        for (int l = 0; l <= n; l++) {
            g[l].clear();
        }

        for (int l = 0; l+len <= n; l++) {
            int r = l+len;
            for (int i = 0; i < n; i++) {
                if (i < n/2) {
                    if (2*i < l) continue;

                    if (2*i+1 < r) {
                        // Case 1. [l, r) shrinks to some smaller interval
                        g[n].pb({a[i]+max(dp[2*i+1][r], dp[0][2*i-l + 1]), l});
                    } else {
                        // Case 2. [l, r) -> [l', r'), same sizes
                        g[l].pb({a[i], 2*i-(r-1)});
                    }
                } else {
                    int x = 2*i-n+1;
                    if (x >= r) continue;

                    if (l < x) {
                        g[n].pb({a[i]+max(dp[l][x], dp[2*i-(r-1)][n]), l});
                    } else {
                        g[l].pb({a[i], 2*i-(r-1)});
                    }
                }
            }
        }

        dij(0);
        for (int l = 0; l+len <= n; l++) {
            dp[l][l+len] = dist[l];
        }
    }

    cout << dp[0][n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

