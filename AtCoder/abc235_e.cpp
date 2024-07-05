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
#define f1(i,a) for(ll i=1;i<(a);i++)
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

struct Edge {
    ll w, u, v;
    bool isG;
    ll idx;
    bool operator <(Edge e) const {
        return w < e.w;
    }
};

// Thinking
// Did not think of offline technique considering all queries at once
// You can do this because queries are not persistent, and query depends
// only on G. When to use this technique it's a question of when does
// it help
int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n, m, q; while (cin >> n >> m >> q) {
        vi me(n+1);
        auto make = [&](ll u) -> void {
            me[u] = -1;
        };
        auto find = y_combinator([&](auto rec, ll u) -> ll {
            return me[u] < 0 ? u : me[u] = rec(me[u]);
        });
        auto unite = y_combinator([&](auto rec, ll u, ll v) -> void {
            u = find(u), v = find(v);
            if (me[u] > me[v]) swap(u, v);
            me[u] += me[v];
            me[v] = u;
        });
        f1(i, n+1) make(i);

        vector<Edge> es;
        f0(i, m) {
            ll u, v, w; cin >> u >> v >> w;
            Edge e = { w, u, v, true};
            es.pb(e);
        }
        f0(i, q) {
            ll u, v, w; cin >> u >> v >> w;
            Edge e = { w, u, v, false, i };
            es.pb(e);
        }
        sort(all(es));

        vb ans(q);
        for (auto [w, u, v, isG, idx] : es) {
            if (find(u) == find(v)) {
                if (!isG) ans[idx] = false;
                continue;
            }
            if (isG) unite(u, v);
            else ans[idx] = true;
        }

        for (auto x : ans) cout << (x ? "Yes" : "No") << endl;
    } 
    
    return 0;
}
