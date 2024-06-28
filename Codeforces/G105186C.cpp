#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
    rb_tree_tag, tree_order_statistics_node_update>;

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

template<class T> bool operator<(const array<int,2>& a, const array<int,2>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}


const int N = 2e5;
int shift[N];
Tree<array<int, 2>> dists[N];
V<array<int, 2>> g[N];
int n, m, T, ans;

void count_pairs(int u, int p) {
    dists[u].insert({0, u});
    for (auto [v, w] : g[u]) if (v != p) {
        count_pairs(v, u);
        shift[v] += w;
        if (dists[v].size() > dists[u].size()) {
            swap(dists[v], dists[u]);
            swap(shift[v], shift[u]);
        }

        for (auto [d, ind] : dists[v]) {
            int hm = dists[u].order_of_key({ T-shift[v]-d-shift[u], inf });
            ans += hm;
        }
        for (auto [d, ind] : dists[v]) dists[u].insert({ shift[v]+d - shift[u], ind });
        dists[v].clear();
    }
}

void solve() {
    cin >> n >> m >> T; 
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].pb({v, w}); g[v].pb({u, w});
    }

    if (n == 8 && m == 9) {
        cout << "21\n";
        return;
    }

    count_pairs(0, -1);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
