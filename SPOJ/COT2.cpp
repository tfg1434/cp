// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18; // 1e9
const int P = 1e9+7; // 998244353;
const double PI = acos(-1.0);

using pi = pair<int,int>;

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;
using vpi = V<pi>;

#define sz(x) ((int)(x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define rep(a) F0R(_,a)

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; } // set a = max(a,b)

template<class T, class U> T fstFalse(T lo, T hi, U f) {
    while (lo < hi) {
        T m = (lo+hi)/2;
        f(m) ? lo = m+1 : hi = m;
    }
    return hi;
}

// Fast IO
void setIn(string s)  { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(s) && fopen((s+".in").c_str(), "r")) setIn(s+".in"), setOut(s+".out"); // for old USACO
}

template<class F> struct y_combinator_result {
    F f;
    template<class T> explicit y_combinator_result(T &&f): f(std::forward<T>(f)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return f(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) yy(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

const int K = 200;

struct query {
    int l, r, lc, ind;
    bool operator < (const query& o) const {
        if (l/K == o.l/K) return r < o.r;
        return l/K < o.l/K;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vi b(n); for (auto&x : b) cin >> x;
    auto a = b; sort(all(b));
    for (auto& x : a) x = lwb(b, x);

    V<vi> g(n);
    rep(n-1) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }

    vi ST(n), EN(n), lvl(n);
    V<vi> lift(18, vi(n));
    int t = -1;
    vi ID(2*n);
    vi opp(2*n);
    yy([&](auto rec, int u, int p) -> void {
        if (p != -1) lvl[u] = lvl[p]+1;
        lift[0][u] = p;

        ST[u] = ++t;
        for (auto v : g[u]) if (v != p) {
            rec(v, u);
        }
        EN[u] = ++t;
        ID[ST[u]] = ID[EN[u]] = u;
        opp[ST[u]] = EN[u]; opp[EN[u]] = ST[u];
    })(0, -1);
    // cout << n << endl;
    // for (int i = 0; i < 2*n; i++) cout << ID[i] << " \n"[i==2*n-1];

    for (int i = 1; i < 18; i++) for (int j = 0; j < n; j++) {
        if (lift[i-1][j] == -1) lift[i][j] = -1;
        else lift[i][j] = lift[i-1][lift[i-1][j]];
    }
    auto lca = [&](int u, int v) {
        if (lvl[u] > lvl[v]) swap(u, v);
        for (int i = 17; i >= 0; i--) if ((lvl[v]-lvl[u]) & p2(i)) 
            v = lift[i][v];
        if (u == v) return u;

        for (int i = 17; i >= 0; i--) if (lift[i][u] != lift[i][v]) {
            u = lift[i][u];
            v = lift[i][v];
        }
        assert(lift[0][u] == lift[0][v]);
        return lift[0][u];
    };

    V<query> queries;
    for (int i = 0; i < q; i++) {
        int u, v; cin >> u >> v; u--; v--;
        if (ST[u] > ST[v]) swap(u, v);
        int lc = lca(u, v);
        if (lc == u) {
            queries.pb({ST[u], ST[v]+1, lc, i});
        } else {
            queries.pb({EN[u], ST[v]+1, lc, i});
        }
    }
    sort(all(queries));

    vi f(n);
    vb vis(n);
    int cnt_dif = 0;
    auto check = [&](int u) {
        if (vis[u]) {
            if (--f[a[u]] == 0) cnt_dif--;
        } else {
            if (f[a[u]]++ == 0) cnt_dif++;
        }
        vis[u] = !vis[u];
    };

    vi ans(q);
    int l = 0, r = 0;
    for (auto query : queries) {
        auto L = query.l;
        auto R = query.r;
        auto lc = query.lc;
        auto ind = query.ind;
        auto u = ID[L];
        auto v = ID[R];

        while (l > L) check(ID[--l]);
        while (r < R) check(ID[r++]);
        while (l < L) check(ID[l++]);
        while (r > R) check(ID[--r]);
        if (lc != u && lc != v) check(lc);
        ans[ind] = cnt_dif;
        if (lc != u && lc != v) check(lc);
    }

    for (auto x : ans) cout << x << '\n';
}

signed main() {
    setIO();
    
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}
