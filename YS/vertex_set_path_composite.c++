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

const int P = 998244353;

struct Info {
    int a, b;
    Info() {
        a = 1;
        b = 0; 
    }
    Info(int a, int b) {
        this->a = a;
        this->b = b;
    }
    int operator()(int x) {
        return (a*x+b) % P;
    }
    friend ostream& operator<<(ostream& os, const Info& rhs) {
        os << rhs.a << ' ' << rhs.b;
        return os;
    }
};
// first apply x, then y
Info merge_info(const Info& x, const Info& y) {
    auto [a, b] = x;
    auto [A, B] = y;
    return Info(A*a % P, (A*b+B) % P);
}

const int max_n = 2e5;
vi g[max_n];
int hr[max_n], par[max_n], sub[max_n];
int tin[max_n], tout[max_n], timer, euler[max_n];
int n, a[max_n], b[max_n];
Info info[max_n];

V<Info> t, T;
void init_tree() {
    int size = 1; 
    while (size < 2*n) size *= 2;
    t.resize(size);
    T.resize(size);
}
void point_upd(int v, int l, int r, int i, const Info& x) {
    if (l == r-1) {
        t[v] = x;
        T[v] = t[v]; // i forgot this, so every query going up received the identity function
        return;
    }
    int m = (l+r)/2;
    if (i < m) point_upd(2*v+1, l, m, i, x);
    else point_upd(2*v+2, m, r, i, x);
    t[v] = merge_info(t[2*v+1], t[2*v+2]);
    T[v] = merge_info(T[2*v+2], T[2*v+1]); // and it was t...
}
void point_upd(int i, const Info& x) { point_upd(0, 0, n, i, x); }
Info range_ask(int v, int l, int r, int L, int R, bool down) {
    if (r <= L || R <= l) return Info();
    if (L <= l && r <= R) return down ? t[v] : T[v];
    int m = (l+r)/2;
    auto left = range_ask(2*v+1, l, m, L, R, down);
    auto right = range_ask(2*v+2, m, r, L, R, down);
    return down ? merge_info(left, right) : merge_info(right, left);
}
Info range_ask(int L, int R, bool down) { return range_ask(0, 0, n, L, R, down); }

void calc_sub(int u, int p) {
    for (int v : g[u]) if (v != p) {
        calc_sub(v, u);
        sub[u] += sub[v];
    }
}
void init_hld(int u, int p) {
    euler[timer] = u;
    tin[u] = timer++;
    par[u] = p;
    int heavy = -1;
    for (int v : g[u]) if (v != p) {
        if (sub[v]*2 >= sub[u]) {
            heavy = v;
            hr[v] = hr[u];
            init_hld(v, u);
        } 
    }
    for (auto v : g[u]) if (v != p && v != heavy) {
        hr[v] = v;
        init_hld(v, u);
    }
    tout[u] = timer;
}
bool is_anc(int u, int v) { 
    if (u == -1) return true;
    if (v == -1) return false;
    return tin[u] <= tin[v] && tout[v] <= tout[u]; 
}

Info vertical_path_query(int u, int v, bool exclusive, bool down) {
    Info res;
    while (u != -1) {
        if (is_anc(hr[u], v)) {
            auto x = range_ask(tin[v]+exclusive, tin[u]+1, down);
            if (down) res = merge_info(x, res);
            else res = merge_info(res, x);
            break;
        }
        auto x = range_ask(tin[hr[u]], tin[u]+1, down);
        if (down) res = merge_info(x, res);
        else res = merge_info(res, x);
        u = par[hr[u]];
    }
    return res;
}
Info path_query(int u, int v) {
    int U = u, V = v;
    while (!is_anc(U, v)) U = par[hr[U]];
    while (!is_anc(V, u)) V = par[hr[V]];
    int lca = is_anc(U, V) ? V : U;
    auto first = vertical_path_query(u, lca, true, false);
    auto second = vertical_path_query(v, lca, false, true);
    return merge_info(first, second);
}

void solve() {
    int q; cin >> n >> q; 
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        info[i] = Info(a, b);
    }

    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }

    fill(all(sub), 1);

    calc_sub(0, -1);
    init_hld(0, -1);
    init_tree();
    for (int i = 0; i < n; i++) point_upd(tin[i], info[i]);

    while (q--) {
        int tp; cin >> tp;
        if (tp == 1) {
            int u, v, x; cin >> u >> v >> x;
            auto res = path_query(u, v);
            cout << res(x) << '\n';
        } else {
            int u, a, b; cin >> u >> a >> b;
            point_upd(tin[u], Info(a, b));
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

