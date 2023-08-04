#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define f first
#define s second
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#ifdef I_AM_NOOB
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__; ((cerr<<exchange(c,',')<<x),...); cerr<<endl; }(__VA_ARGS__);
#else
#define gg(...) 777771449
#endif

constexpr ll INFF = 1e18;
constexpr ll P = 1e9+7;
// constexpr ll P = 998244353;

// An easy 2-SAT problem. In this solution I don't need to define all these helper clause
// functions, just get AND with XOR 0 and 1 for example. Need only one, "imply".
// With 2-SAT use zero-index b/c working with 2*n!
// Clone of a slightly harder USACO problem "Left Out"
struct TwoSat {
    ll n;
    vector<vector<ll>> g, gr;
    TwoSat(ll _n) {
        n = _n;
        g.resize(2*n);
        gr.resize(2*n);
        vis.resize(2*n);
        comp.resize(2*n);
    }

    vector<ll> vis, comp;
    vector<ll> topoOrder;

    void add_edge(ll u, ll v) {
        g[u].pb(v);
        gr[v].pb(u);
    }

    void dfs(ll u) {
        vis[u] = true;
        topoOrder.pb(u);

        for (auto v : g[u]) {
            if (!vis[v]) dfs(v);
        }
    }

    void scc(ll u, ll id) {
        vis[u] = true;
        comp[u] = id;

        for (auto v : gr[u]) {
            if (!vis[v]) scc(v, id);
        }
    }

    bool satisfiable() {
        fill(all(vis), false);
        for (ll i = 0; i < 2*n; i++) {
            if (!vis[i]) dfs(i);
        }
        gg(g);
        fill(all(vis), false);
        reverse(all(topoOrder));
        ll id = 0;
        for (auto u : topoOrder) {
            if (!vis[u]) {
                scc(u, id++);
            }
        }

        for (ll i = 0; i < n; i++) {
            if (comp[i] == comp[i+n]) return false;
        }

        return true;
    }

    //i = col, j = row
    void add_clause_or(ll i, bool f, ll j, bool g) {
        add_edge(i + (f ? n : 0), j + (g ? 0 : n));
        add_edge(j + (g ? n : 0), i + (f ? 0 : n));
    }
    void add_clause_xor(ll i, bool f, ll j, bool g) {
        add_clause_or(i, f, j, g);
        add_clause_or(i, !f, j, !g);
    }
    //both have same value
    void add_clause_and(ll i, bool f, ll j, bool g) {
        add_clause_xor(i, !f, j, g);
    }
};

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        vector<vector<ll>> ma(n, vector<ll>(n));
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                char c; cin >> c;
                ma[i][j] = c-'0';
            }
        }
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                char c; cin >> c;
                ma[i][j] ^= c-'0';
            }
        }

        TwoSat solver(2*n);
        //columns
        //i is column, j is row
        for (ll i = 0; i < n; i++) for (ll j = 0; j < n; j++) {
            if (ma[j][i] == 0) {
                solver.add_clause_and(i, true, j+n, true);
                // gg("AND", i, j);
            } else {
                solver.add_clause_xor(i, true, j+n, true);
                // gg("XOR", i, j);
            }
        }
        
        cout << (solver.satisfiable() ? "YES" : "NO") << endl;
    } 
    
    return 0;
}
