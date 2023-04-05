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
constexpr ll N = 2e5+5;
vector<ll> adj[N];
ll lvl[N], h[N];
// constexpr ll P = 998244353;

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n; while (cin >> n) {
        for (ll i = 0; i < n-1; i++) {
            ll u, v; cin >> u >> v;
            adj[u].pb(v); adj[v].pb(u);
        }
        
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        y_combinator([&](auto rec, ll u, ll p, ll l) -> void {
            lvl[u] = l;
            ll mx = -1;
            for (auto v : adj[u]) {
                if (v == p) continue;
                rec(v, u, l+1);
                mx = max(mx, h[v]);
            }
            h[u] = mx+1;
        })(1, -1, 0);

        ll ans = 0;
        for (ll i = 1; i <= n; i++) {
            ll mx1 = 0, v1;
            for (auto v : adj[i]) {
                if (h[v] > h[i]) continue;
                if (h[v] > mx1) {
                    v1 = v;
                    mx1 = h[v];
                }
            }
            ll mx2 = 0, v2;
            for (auto v : adj[i]) {
                if (h[v] > h[i]) continue;
                if (h[v] > mx2 && v != v1) {
                    v2 = v;
                    mx2 = h[v];
                }
            }
            if (adj[i].size() >= 2) ans = max(ans, mx1+mx2+2);
            else ans = max(ans, mx1+1);
            // gg(mx1, mx2);
        }

        cout << ans << endl;
    } 
    
    return 0;
}
