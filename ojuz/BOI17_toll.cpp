// spent some time confused b/c i thought that queries had to be between
// different blocks. but this is only edges, queries in the same block are
// valid. and of course the distance between u and u is 0

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }

// dist_to(src class in m, dest layer, dest layer class)
// dist_from(src layer, src class, dest class in m)
const int max_k = 5, max_n = 5e4;
int k, n, m, q, dist_to[max_k][max_n][max_k], dist_from[max_n][max_k][max_k];
const int max_q = 10000;
int ans[max_q];
array<int, 2> queries[max_q];
V<array<int, 2>> g[max_n][max_k];

void dnc(int l, int r, vi query_inds) {
    if (l == r-1) {
        for (int ind : query_inds) {
            auto [l, r] = queries[ind];
            if (l/k != r/k) while (true);
            ans[ind] = l == r ? 0 : -1;
        }
        return;
    }

    int m = (l+r)/2;
    {
        for (int from = 0; from < k; from++) {
            for (int i = m; i < r; i++) {
                fill(all(dist_to[from][i]), inf);
            }
        }
        for (int from = 0; from < k; from++) {
            dist_to[from][m][from] = 0;
            for (int i = m; i < r-1; i++) {
                for (int now = 0; now < k; now++) {
                    for (auto [w, nxt] : g[i][now]) {
                        dist_to[from][i+1][nxt] = min(dist_to[from][i+1][nxt], dist_to[from][i][now]+w);
                    }
                }
            }
        }
    }
    {
        for (int src_layer = l; src_layer <= m; src_layer++) {
            for (int src_class = 0; src_class < k; src_class++) {
                fill(all(dist_from[src_layer][src_class]), inf);
            }
        }
        for (int dest_class = 0; dest_class < k; dest_class++) {
            dist_from[m][dest_class][dest_class] = 0;
            for (int src_layer = m-1; src_layer >= l; src_layer--) {
                for (int src_class = 0; src_class < k; src_class++) {
                    for (auto [w, nxt_class] : g[src_layer][src_class]) {
                        dist_from[src_layer][src_class][dest_class] = min(
                            dist_from[src_layer][src_class][dest_class],
                            w+dist_from[src_layer+1][nxt_class][dest_class]
                        );
                    }
                }
            }
        }
    }

    vi todo[2];
    for (int ind : query_inds) {
        auto [l, r] = queries[ind];
        if (l/k <= m && m <= r/k) {
            int res = inf;
            for (int m_class = 0; m_class < k; m_class++) {
                res = min(res, dist_from[l/k][l%k][m_class]+dist_to[m_class][r/k][r%k]);
            }
            if (res == inf) res = -1;
            ans[ind] = res;
        } else {
            todo[l/k >= m].pb(ind);
        }
    }
    dnc(l, m, todo[0]);
    dnc(m, r, todo[1]);
}

void solve() {
    cin >> k >> n >> m >> q; 
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u/k][u%k].pb({w, v%k});
    }

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }
    vi query_inds(q); iota(all(query_inds), 0);

    dnc(0, (n-1)/k+1, query_inds);
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
