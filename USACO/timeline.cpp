#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
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
ll n, m, c;

int main() {
    // cin.tie(0) -> ios::sync_with_stdio(0);
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    
    while (cin >> n >> m >> c) {
        vector<ll> s(n+1); 
        for (ll i = 1; i <= n; i++) {
            cin >> s[i];
        }
        vector<vector<pll>> adj(n+1);
        for (ll i = 0; i < c; i++) {
            ll a, b, x; cin >> a >> b >> x;
            adj[a].pb({b, x});
        }

        vector<ll> topo, vis(n+1);
        for (ll i = 1; i <= n; i++) {
            if (vis[i]) continue;
            y_combinator([&](auto rec, ll u) -> void {
                if (vis[u]) return; 
                vis[u] = 1;
                for (auto [v, dist] : adj[u]) {
                    rec(v);
                }
                topo.pb(u);
            })(i);
        }
        reverse(all(topo));
        gg(topo);

        for (ll i = 0; i < n; i++) {
            for (auto [v, dist] : adj[topo[i]]) {
                s[v] = max(s[v], s[topo[i]]+dist); 
            }
        }

        for (ll i = 1; i <= n; i++) {
            cout << s[i] << endl;
        }
    } 
    
    return 0;
}
