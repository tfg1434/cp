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
template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
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

// Finding all bridges in the graph
// https://codeforces.com/blog/entry/68138?locale=en
int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n, r; while (cin >> n >> r) {
        vector<vi> g(n);
        map<ll, ll> mp;
        f0(i, r) {
            ll u, v; cin >> u >> v;
            u--; v--;
            g[u].pb(v); g[v].pb(u);
        }

        ll ans = 0;
        vi dep(n);
        vb vis(n);
        vector<vi> span(n), back(n);
        auto dfs = y_combinator([&](auto rec, ll u, ll p) -> void {
            gg(u);
            vis[u] = true;
            dep[u] = dep[p]+1;
            for (auto v : g[u]) {
                if (p==v) continue;
                if (vis[v]) {
                    back[u].pb(v); 
                    gg(u, v);
                } else {
                    span[u].pb(v);
                    span[v].pb(u);
                    rec(v, u);
                }
            }
        });
        //returns 
        auto dfs2 = y_combinator([&](auto rec, ll u, ll p) -> ll {
            ll cnt = 0;
            for (auto v : span[u]) {
                if (v == p) continue;
                cnt += rec(v, u);
            }
            for (auto v : back[u]) {
            gg(u, v, dep[u], dep[v]);
                if (dep[v] < dep[u]) cnt++;
                if (dep[v] > dep[u]) cnt--;
            }

            if (cnt == 0 && u != 0) {
                ans++;
                return 1001;
            }
            return cnt;
        });

        dfs(0, 0);
        dfs2(0, 0);
        gg(back);
        cout << (ans+1)/2 << endl;
    } 
    
    return 0;
}
