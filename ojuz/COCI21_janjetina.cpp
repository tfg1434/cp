// passes subtask 2, subtask 1+3 WA
// i think that i may be overcounting paths that are a line somehow, but i'm not sure how
// i called it quits since the code is in a weird state of being workable but also sloppy

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less_equal<T>, 
    rb_tree_tag, tree_order_statistics_node_update>;
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


int n;
vi sub;
V<bool> del;
int ans;
V<V<pair<int, array<int, 2>>>> g;

void find_sub(int u, int p) {
    sub[u] = 1;
    for (auto [v, wi] : g[u]) if (v != p && !del[v]) {
        find_sub(v, u);
        sub[u] += sub[v];
    }
}

int find_ctd(int u, int p, int sub_siz) {
    for (auto [v, wi] : g[u]) if (v != p && !del[v]) {
        if (2*sub[v] >= sub_siz) {
            return find_ctd(v, u, sub_siz);
        }
    }
    return u;
}

V<pair<array<int, 2>, array<int, 2>>> paths;
void find_paths(int u, int p, int d, array<int, 2> mx, int son) {
    for (auto [v, wi] : g[u]) if (v != p && !del[v]) {
        if (p == -1) {
            son = v;
        }
        ckmax(mx, wi);
        paths.pb({mx, { d+1, son }});
        find_paths(v, u, d+1, mx, son);
        if (p == -1) {
            mx = {0, -1};
        }
    }
}

void process_ctd(int ctd, int p) {
    find_paths(ctd, p, 0, {0, -1}, -1);
    sort(all(paths));
    Tree<int> s;
    for (auto [wi, dson] : paths) {
        auto [d, son] = dson;
        int mx = wi[0];
        if (mx >= d) ans++;
        ans += s.order_of_key(mx-d+1);
        s.insert(d);
    }
    s.clear();

    map<int, V<pair<array<int, 2>, int>>> paths_by_son;
    for (auto [wi, dson] : paths) {
        auto [d, son] = dson;
        paths_by_son[son].pb({wi, d});
    }
    for (auto [son, spaths] : paths_by_son) {
        for (auto [wi, d] : spaths) {
            int mx = wi[0];
            ans -= s.order_of_key(mx-d+1);
            s.insert(d);
        }
        s.clear();
    }

    paths.clear();
}

void cd(int u) {
    find_sub(u, -1);
    int ctd = find_ctd(u, -1, sub[u]);
    process_ctd(ctd, -1);
    del[ctd] = true;
    for (auto [v, wi] : g[ctd]) if (!del[v]) {
        cd(v);
    }
}

void solve() {
    int k; cin >> n >> k; 
    g.resize(n);
    del.resize(n);
    sub.resize(n);

    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--; w -= k;
        g[u].pb({v, {w, i}}); g[v].pb({u, {w, i}});
    }
    cd(0);
    cout << 2*ans << '\n';
}

signed main() {
    Tree<int> test;
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
