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

// Kosaraju's Algorithm to solve 2-SAT
// This is wrong. The naive 2-SAT method (which is not this) runs in O(n^2).
// My idea to solve in linear time doesn't work b/c it doesn't encode the idea of cards
int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        vector<vector<ll>> g(2*n+1), gr(2*n+1);
        vector<ll> comp(2*n+1), topo_order;
        vector<bool> vis(2*n+1);

        auto add_edge = [&](ll u, ll v) -> void {
            g[u].pb(v);
            gr[v].pb(u);
        };
        auto add_clause_or = [&](ll i, bool f, ll j, bool g) -> void {
            add_edge(i + (f ? n : 0), j + (g ? 0 : n));
            add_edge(j + (g ? n : 0), i + (f ? 0 : n));
        };
        auto add_clause_xor = [&](ll i, bool f, ll j, bool g) -> void {
            add_clause_or(i, f, j, g);
            add_clause_or(i, !f, j, !g);
        };

        //toposort
        auto dfs = y_combinator([&](auto rec, ll u) -> void {
            vis[u] = true;
            for (auto v : g[u]) {
                if (!vis[v]) rec(v);    
            }
            topo_order.pb(u);
        });
        
        //find sccs
        auto scc = y_combinator([&](auto rec, ll u, ll id) -> void {
            vis[u] = true;
            comp[u] = id;

            for (auto v : gr[u]) {
                if (!vis[v]) rec(v, id);
            }
        });

        for (ll i = 0; i < n; i++) {
            ll p, q; cin >> p >> q;
            add_clause_or(p, true, q, true);
            add_clause_or(p, false, q, false);
        }
        for (ll i = 1; i <= 2*n; i++) {
            if (!vis[i]) dfs(i);
        }
        reverse(all(topo_order));
        ll id = 1;
        for (auto v : topo_order) {
            gg(v);
            if (vis[v]) continue;
            scc(v, id++);
        }

        bool ans = true;
        gg(comp);
        for (ll i = 1; i <= n; i++) {
            if (comp[i] == comp[i+n]) {
                ans = false;
                break;
            }
        }

        cout << (ans ? "possible" : "impossible") << endl;
    } 
    
    return 0;
}
