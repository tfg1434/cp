#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define vi vector<ll>
#define vb vector<bool>
#define f0(i,a) for(ll i=0;i<(a);i++)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
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
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        vector<vi> children(n+1);
        vi par(n+1);
        for (ll i = 1; i <= n-1; i++) {
            ll p; cin >> p;
            children[p].pb(i+1);
            par[i+1] = p;
        }

        vi cost(n+1), old(n+1), wen(n+1);
        for (ll i = 1; i <= n; i++) cin >> cost[i];
        for (ll i = 1; i <= n; i++) cin >> old[i];
        for (ll i = 1; i <= n; i++) cin >> wen[i];
        vi painted(n+1);
        // gg(children);

        ll ans = 0;
        queue<ll> q; q.push(1);
        while (!q.empty()) {
            ll m = q.size();
            for (ll i = 0; i < m; i++) {
                ll u = q.front(); q.pop();
                // gg(u, painted[par[u]]);
                if (painted[par[u]] != 0){
                    old[u] = painted[par[u]];
                    painted[u] = painted[par[u]];
                    for (auto v : children[u]) {
                        old[v] = painted[u];
                        painted[v] = painted[u];
                    }
                } 
                if (old[u] != wen[u]) {
                    ans += cost[u];
                    // gg(u, cost[u]);
                    painted[u] = wen[u];
                } else {
                    ll d = 0;
                    for (auto v : children[u]) {
                        if (wen[v] != old[v] && wen[v] == wen[u]) {
                            d += cost[v];
                        }
                    }

                    d -= cost[u];
                    if (d > 0) {
                        ans += cost[u];
                        painted[u] = wen[u];
                    }
                }

                for (auto v : children[u]) {
                    q.push(v);
                }
            }
        }

        cout << ans << endl;
    } 
    
    return 0;
}
