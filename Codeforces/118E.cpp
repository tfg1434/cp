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

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n, m; while (cin >> n >> m) {
        vector<vi> g(n+1);
        set<pll> es;
        f0(i, m) {
            ll u, v; cin >> u >> v;
            g[u].pb(v); g[v].pb(u);
        }

        vi vis(n+1), dp(n+1), lvl(n+1);
        vector<vi> span(n+1), back(n+1);
        y_combinator([&](auto rec, ll u, ll p) -> void {
            vis[u] = 1;
            lvl[u] = lvl[p]+1;
            for (auto v : g[u]) {
                if (v == p) continue;
                if (vis[v]) {
                    if (lvl[v] < lvl[u]) back[v].pb(u);
                    continue;
                }
                span[u].pb(v);
                rec(v, u);
            }
        })(1, 1);

        bool ok = true;
        for (auto&x:vis) x = 0;
        y_combinator([&](auto rec, ll u, ll p) -> ll {
            ll cnt = 0;
            vis[u] = 1;
            for (auto v : g[u]) {
                if (v == p) continue;
                if (vis[v]) {
                    if (lvl[v] < lvl[u]) cnt++;
                    if (lvl[v] > lvl[u]) cnt--;
                    continue;
                }
                cnt += rec(v, u);
            }
            if (u != 1) ok &= cnt != 0;
            gg(cnt);
            return cnt;
        })(1, 1);
        
        if (!ok) cout << 0 << endl;
        else {
            f1(u, n+1) {
                for (auto v : span[u]) {
                    cout << u << ' ' << v << endl;
                }
            }
            f1(u, n+1) {
                for (auto v : back[u]) {
                    cout << v << ' ' << u << endl;
                }
            }
        }
    } 
    
    return 0;
}
