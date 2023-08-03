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

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n, m; while (cin >> n >> m) {
        vector<ll> a(n+1); for (ll i = 1; i <= n; i++) cin >> a[i];

        vector<set<pll>> sons(n+1);
        vector<vector<ll>> adj(n+1);
        for (ll i = 0; i < n-1; i++) {
            ll u, v; cin >> u >> v;
            adj[u].pb(v); adj[v].pb(u);
        }

        vector<ll> sz(n+1), sum(n+1), son(n+1), fa(n+1);
        y_combinator([&](auto rec, ll u, ll p) -> void {
                // gg(u, p);
            sz[u] = 1;
            sum[u] = a[u];
            fa[u] = p;
            for (auto v : adj[u]) {
                if (v == p) continue;
                rec(v, u);
                sum[u] += sum[v];
                sz[u] += sz[v];
                sons[u].insert({ -sz[v], v });
                // if (sz[v] > sz[son[u]] || sz[v] == sz[son[u]] && )
            }

            son[u] = sons[u].empty() ? 0 : (*sons[u].begin()).second;

        })(1, 0);
        // gg(1);

        for (ll i = 0; i < m; i++) {
            ll tp, x; cin >> tp >> x;
            if (tp == 1) {
                cout << sum[x] << endl;
            } else {
                ll p = fa[x], v = son[x];
                if (!v) continue;

                gg(p, x, v);
                sz[x] -= sz[v];
                sum[x] -= sum[v];
                sons[x].erase({ -sz[v], v });
                son[x] = sons[x].empty() ? 0 : (*sons[x].begin()).second;
                fa[x] = v;
                sz[v] += sz[x];
                sum[v] += sum[x];
                sons[v].insert({ -sz[x], x });
                son[v] = (*sons[v].begin()).second;
                fa[v] = p;

                sons[p].erase({ -sz[v], x });
                sons[p].insert({ -sz[v], v });
                son[p] = (*sons[p].begin()).second;
            }
        }
    } 
    
    return 0;
}
