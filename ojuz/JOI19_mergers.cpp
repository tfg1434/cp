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

int n, k;
struct Bundle {
    int bad;
    map<int, int> col_fre;
};
V<Bundle> bundle;
vi tot_fre, s;
V<bool> is_crit;
V<V<array<int, 2>>> g;

void find_crit_edges(int u, int p, int edge_ind) {
    for (auto [v, ind] : g[u]) if (v != p) {
        find_crit_edges(v, u, ind);
        if (bundle[v].col_fre.size() > bundle[u].col_fre.size()) {
            swap(bundle[u], bundle[v]);
        }
        bundle[u].bad += bundle[v].bad;
        for (auto [x, y] : bundle[v].col_fre) {
            if (bundle[u].col_fre.count(x)) {
                bundle[u].bad -= 2;
            }
            bundle[u].col_fre[x] += y;
            // bundle[u].col_fre[x] += y;
            // if (y < tot_fre[x] && bundle[u].col_fre[x] == tot_fre[x]) {
                // bundle[u].bad--;
            // }
        }
    }

    if (!bundle[u].col_fre.count(s[u]))
        bundle[u].bad++;
    bundle[u].col_fre[s[u]]++;
    if (bundle[u].col_fre[s[u]] == tot_fre[s[u]]) {
        bundle[u].bad--;
    }

    if (edge_ind != -1) {
        is_crit[edge_ind] = !bundle[u].bad;
        // if (is_crit[edge_ind]) {
            // ps(bundle[u].bad, bundle[u].col_fre);
            // ps(u+1, p+1);
        // } 
    }
}

int cur_cc = -1;
vi vis, crit_edges_touching;
void find_cc(int u) {
    vis[u] = cur_cc;
    for (auto [v, ind] : g[u]) {
        if (is_crit[ind]) {
            crit_edges_touching[cur_cc]++;
            continue;
        }
        if (vis[v] != -1) {
            continue;
        }
        find_cc(v);
    }
}

void solve() {
    cin >> n >> k;
    g.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb({v, i}); g[v].pb({u, i});
    }
    s.resize(n);
    tot_fre.resize(k);
    for (int& i : s) cin >> i, i--, tot_fre[i]++;

    is_crit.resize(n-1);
    bundle.resize(n);
    find_crit_edges(0, -1, -1);
    vis.resize(n, -1);
    crit_edges_touching.resize(n);
    for (int i = 0; i < n; i++) if (vis[i] == -1) {
        cur_cc++;
        find_cc(i);
        // ps(cur_cc, crit_edges_touching, vis);
    }

    int leaves = 0;
    while (cur_cc >= 0) {
        leaves += crit_edges_touching[cur_cc--] == 1;
    }
    // ps(leaves);
    cout << (leaves+1)/2 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
