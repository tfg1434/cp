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

int n, w;
const int LOG = 17;
vi assign_time, lvl;
V<array<int, LOG>> lift;
V<vi> sons;

vi t;
void init_tree() {
    int siz = 1;
    while (siz < 2*n) siz *= 2;
    t.assign(siz, -1);
}
void build(int u=0, int l=1, int r=n) {
    if (l == r-1) {
        t[u] = assign_time[l];
        return;
    }
    int m = (l+r)/2;
    build(2*u+1, l, m);
    build(2*u+2, m, r);
    t[u] = max(t[2*u+1], t[2*u+2]);
}
int range_max(int L, int R, int u=0, int l=1, int r=n) {
    if (r <= L || R <= l) return -1;
    if (L <= l && r <= R) return t[u];
    int m = (l+r)/2;
    return max(range_max(L, R, 2*u+1, l, m), range_max(L, R, 2*u+2, m, r));
}

void dfs(int u) {
    for (int v : sons[u]) {
        lift[v][0] = u;
        lvl[v] = lvl[u]+1;
        dfs(v);
    }
}
int find_lca(int u, int v) {
    if (u == v) return u;
    if (lvl[u] > lvl[v]) swap(u, v);
    for (int i = LOG-1; i >= 0; i--) if ((lvl[v]-lvl[u])&(1 << i)){
        v = lift[i][v];
    }
    for (int i = LOG-1; i >= 0; i--) {
        if (lift[i][u] != lift[i][v]) {
            u = lift[i][u];
            v = lift[i][v];
        }
    }
    return lift[0][u];
}

void solve() {
    cin >> n >> w;
    lvl.assign(n, 0);
    lift.assign(n);
    sons.assign(n, vi());
    for (int u = 1; u < n; u++) {
        int p; cin >> p; p--;
        sons[p].pb(u);
    }
    dfs(0);
    for (int i = 1; i < LOG; i++) {
        for (int u = 0; u < n; u++) {
            lift[i][u] = lift[i-1][u] == -1 ? -1 : lift[i-1][lift[i-1][u]];
        }
    }

    assign_time.resize(n);
    V<array<int, 2>> queries;
    for (int i = 0; i < n-1; i++) {
        // the edge from x to its parent has weight y now
        int x, y; cin >> x >> y; x--;
        assign_time[x] = i;
        queries.pb({x, y});
    }
    init_tree();
    build();

    // after query i, how many paths are "full" (have all edges assigned)
    vi cnt_full_paths(n-1);
    for (int i = 0; i < n; i++) {
        int lca = find_lca(i, (i+1)%n);
        // note: these edges are ordered by the moment it gets assigned
        int max_edge = max(range_max(lca+1, i+1), range_max(lca+1, i+2));
        cnt_full_paths[max_edge]++;
    }
    for (int i = 0; i < n-2; i++) {
        cnt_full_paths[i+1] += cnt_full_paths[i];
    }

    int Y = 0;
    for (int i = 0; i < n-1; i++) {
        auto [x, y] = queries[i];
        Y += y;
        int ans = n*w - Y*(n-2) - cnt_full_paths[i]*(w-Y);
        cout << ans << '\n';
    }


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
