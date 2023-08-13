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
ll LOG2(ll x){ return __builtin_clzll(1ll) - __builtin_clzll(x); }
bool isPow2(ll n) {
    return n && ((n & (n-1)) == 0);
}
ll LOG2C(ll x) {
    if (isPow2(x)) return LOG2(x);
    return LOG2(x)+1;
}

constexpr ll INFF = 1e18;
constexpr ll P = 1e9+7;
// constexpr ll P = 998244353;

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n; while (cin >> n) {
        vector<vi> g(n+1);
        f0(i, n-1) {
            ll u, v; cin >> u >> v;
            g[u].pb(v); g[v].pb(u);
        }

        vi sz(n+1), SZ(n+1);
        y_combinator([&](auto rec, ll u, ll p) -> void {
            sz[u] = 1;
            for (auto v : g[u]) {
                if (v == p) continue;
                rec(v, u);
                sz[u] += sz[v];
            }
        })(1, 0);
        y_combinator([&](auto rec, ll u, ll p) -> void {
            SZ[u] = sz[u];
            for (auto v : g[u]) {
                if (v == p) continue;
                rec(v, u);
                SZ[u] += SZ[v];
            }
        })(1, 0);

        auto f = [&](ll u) -> ll {
            return LOG2C(sz[u]) + SZ[u];
        };
        ll ans = 0;
        y_combinator([&](auto rec, ll u, ll p) -> void {
            ll sum = 0, cnt = 0;
            for (auto v : g[u]) {
                if (v == p) continue;
                sum += f(v);
                cnt++;
            }
            ll t = sum + LOG2C(cnt + 1);
            
            if (f(u) > t) {
                ans += LOG2C(cnt+1); 
                for (auto v : g[u]) {
                    if (v == p) continue;
                    ans++;
                    rec(v, u);
                }
            } else {
                ans += f(u);
            }

        })(1, 0);

        cout << ans << endl;
    } 
    
    return 0;
}
