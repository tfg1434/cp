#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;

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

const int N = 5e5;
int par[N], hr[N], sub[N], n;
int tin[N], tout[N], timer, euler[N];
V<array<int, 2>> g[N];

void calc_sub(int u, int p) {
    for (auto [v, i] : g[u]) if (v != p) {
        calc_sub(v, u);
        sub[u] += sub[v];
    }
}

void init_hld(int u, int p) {
    euler[tin[u]] = u;
    tin[u] = timer++;
    par[u] = p;
    int hc = -1;
    for (auto [v, i] : g[u]) if (v != p) {
        if (2*sub[v] >= sub[u]) {
            hc = v;
            hr[v] = hr[u];
            init_hld(v, u);
        }
    }
    for (auto [v, i] : g[u]) if (v != p && v != hc) {
        hr[v] = v;
        init_hld(v, u);
    }
    tout[u] = timer;
}

struct SegmentTree {
    vi t, buf;
    function<int(int, int)> merge;
    void pd(int v) {
        if (buf[v] == inf) return;
        ckmin(t[v], buf[v]);
        if (2*v+2 < buf.size()) {
            ckmin(buf[2*v+1], buf[v]);
            ckmin(buf[2*v+2], buf[v]);
        }
        buf[v] = inf;
    }
    void build(int v, int l, int r, const vi& a) {
        if (l == r-1) {
            t[v] = a[l]; 
            return;
        }
        int m = (l+r)/2;
        build(2*v+1, l, m, a);
        build(2*v+2, m, r, a);
        t[v] = merge(t[2*v+1], t[2*v+2]);
    }
    int range_query(int v, int l, int r, int L, int R) {
        pd(v);
        if (r <= L || R <= l) return inf;
        if (L <= l && r <= R) return t[v];
        int m = (l+r)/2;
        return merge(range_query(2*v+1, l, m, L, R), range_query(2*v+2, m, r, L, R));
    }
    void range_ckmin(int v, int l, int r, int L, int R, int x) {
        pd(v);
        if (r <= L || R <= l) return;
        if (L <= l && r <= R) {
            buf[v] = x;
            pd(v);
            return;
        }
        int m = (l+r)/2;
        range_ckmin(2*v+1, l, m, L, R, x);
        range_ckmin(2*v+2, m, r, L, R, x);
        t[v] = merge(t[2*v+1], t[2*v+2]);
    }
    SegmentTree(const function<int(int, int)>& merge, const vi& a) {
        this->merge = merge;
        int size = 1;
        while (size < 2*n) size *= 2;
        t.resize(size);
        buf.resize(size, inf);
        build(0, 0, n, a);
    }
};

bool is_anc(int u, int v) {
    if (u == -1) return true;
    if (v == -1) return false;
    return tin[u] <= tin[v] && tout[v] <= tout[u]; 
}
int vert_path_query(int u, int v, SegmentTree& tr) {
    int res = -inf;
    while (true) {
        if (is_anc(hr[u], v)) {
            ckmax(res, tr.range_query(0, 0, n, tin[v], tin[u]+1));
            break;
        }
        ckmax(res, tr.range_query(0, 0, n, tin[hr[u]], tin[u]+1));
        u = par[hr[u]];
    }
    return res;
}
int lca(int u, int v) {
    int lca0 = u, lca1 = v;
    while (!is_anc(lca0, v)) lca0 = par[hr[lca0]];
    while (!is_anc(lca1, u)) lca1 = par[hr[lca1]];
    int lca = lca0;
    if (is_anc(lca0, lca1)) lca = lca1;
    return lca;
}
int path_query(int u, int v, SegmentTree& tr) {
    int lc = lca(u, v);
    return tr.merge(vert_path_query(u, lc, tr), vert_path_query(v, lc, tr));
}

void solve() {
    int m; cin >> n >> m;    

    hr[0] = 0;
    timer = 0;
    for (int i = 0; i < n; i++) {
        sub[i] = 1;
        g[i].clear();
    }

    V<array<int, 3>> a(m);
    V<array<int, 2>> e(m);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v >> a[i][0] >> a[i][1];
        u--; v--; a[i][0]--; a[i][1]--; a[i][2] = i;
        if (i < n-1) {
            g[u].pb({v, i}); g[v].pb({u, i});
        }
        e[i] = {u, v};
    }

    calc_sub(0, -1);
    init_hld(0, -1);

    vi _tl(n);
    for (int i = 0; i < n; i++) _tl[i] = a[euler[i]][0];
    SegmentTree tl([](int x, int y) { 
        if (x == inf) return y;
        if (y == inf) return x;
        return max(x, y);
    }, _tl);
    for (int i = n-1; i < m; i++) {
        auto [u, v] = e[i];
        int lc = lca(u, v);
        // push the red left border to the max left border + 1
        ckmax(a[i][0], path_query(u, v, tl)+1);
    }

    vi _mx(n, m);
    SegmentTree mx([](int x, int y) {
        if (x == inf) return y;
        if (y == inf) return x;
        return max(x, y);
    }, _mx);
    for (int i = n-1; i < m; i++) {
        auto [u, v] = e[i];
        int lc = lca(u, v);
        mx.range_ckmin(0, 0, n, tin[lc], tin[u]+1, a[i][1]);
        mx.range_ckmin(0, 0, n, tin[lc], tin[v]+1, a[i][1]);
    }
    for (int i = 0; i < n-1; i++) {
        auto [u, v] = e[i];
        ckmin(a[i][1], path_query(u, v, mx)-1);
    }
    for (int i = 0; i < m; i++) if (a[i][0] > a[i][1]) {
        cout << "NO\n";
        return;
    }
    vi ans(m);
    sort(all(a));
    multiset<array<int, 2>> rbs;
    for (int i = 0, j = 0; i < m; i++) {
        while (j < m && a[j][0] <= i) {
            rbs.insert({ a[j][1], a[j][2] });
            j++;
        }
        if (!rbs.size() || (*begin(rbs))[0] < i) {
            cout << "NO\n";
            return;
        }
        ans[(*begin(rbs))[1]] = i;
        rbs.erase(begin(rbs));
    }

    cout << "YES\n";
    for (int i = 0; i < m; i++) cout << ans[i]+1 << " \n"[i==m-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
