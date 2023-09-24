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
    
    if (fopen("deleg.in", "r")) {
        freopen("deleg.in", "r", stdin);
        freopen("deleg.out", "w", stdout);
    } 

    ll n; while (cin >> n) {
        vector<vi> g(n+1);
        f0(i, n-1) {
            ll u, v; cin >> u >> v;
            g[u].pb(v); g[v].pb(u);
        }

        vi dp(n+1);
        auto dfs = y_combinator([&](auto rec, ll u, ll p, ll k) -> bool {
            dp[u] = 1;
            vi num;
            for (auto v : g[u]) {
                if (v == p) continue;
                if (!rec(v, u, k)) return false;
                dp[u] += dp[v];
                num.pb(dp[v]);
            }
            if (dp[u] != n) num.pb(n - dp[u]);

            ll cnt = 0;
            vi vis(n+1);
            for (auto x : num) {
                ll z = x % k; if (z == 0) continue;
                if (vis[k-z]) cnt--, vis[k-z]--;
                else cnt++, vis[z]++;
            }

            if (cnt) return false; 
            return true;
        });

        string ans(n-1, '0');
        f1(i, n) {
            if ((n-1) % i != 0) continue;
            ans[i-1] = dfs(1, 1, i) ? '1' : '0';
        }

        cout << ans << endl;
    }
    
    return 0;
}
