#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
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
using tp = tuple<ll, ll, ll>;

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n,m,k; cin >> n >> m >> k;
    vector<vector<tp>> adj(n+1);
    vector<ll> dist(n+1);
    priority_queue<tp> q;
    for (ll i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].eb(w, 0, v); adj[v].eb(w, 0, u);
    }
    for (ll i = 0; i < k; i++) {
        ll v, w; cin >> v >> w;
        adj[1].eb(w, -1, v);
    }

    vector<bool> upd(n+1, true);
    for (q.emplace(0, 0, 1); !q.empty(); ) {
        auto [w, removable, u] = q.top(); q.pop();
        // cout << w << ' '<< removable <<' '<< u << endl;
        if (upd[u]) {
            for (auto [ww, rremovable, uu] : adj[u]) {
                q.emplace(w - ww, rremovable, uu);
            }
            k += removable;
            upd[u] = false;
        }
    }
    
    cout << k << endl;
    
    return 0;
}
