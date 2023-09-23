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

// Important observation in functional graph:
// Once you find the cycle, everything attached to it is a tree.
int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n; while (cin >> n) {
        vi f(n+1);
        vector<vi> g(n+1);
        f1(i, n+1) {
            ll x; cin >> x;
            f[i] = x;
            g[x].pb(i);
        }

        ll ans = 0, comp = 1;
        vi vis(n+1);
        f1(i, n+1) {
            if (vis[i]) continue;
            ll u = i, v = f[i];
            while (u != v) u = f[u], v = f[f[v]];
            vi cyc = { u };
            while (f[cyc.back()] != u) cyc.pb(f[cyc.back()]);
            for (auto t : cyc) vis[t] = true;

            vb used(n+1);
            auto dfs = y_combinator([&](auto rec, ll u) -> void {
                vis[u] = 1;
                for (auto v : g[u]) if (!vis[v]) {
                    rec(v);
                    if (!used[v]) used[u] = true;
                }
                ans += used[u];
            });

            vb a;
            for (auto t : cyc) {
                dfs(t);
                a.pb(used[t]);
            }

            f0(j, a.size()) if (a[j] == 1){
                rotate(a.begin(), a.begin() + j, a.end());
            }
            ll cur = 0;
            f0(j, a.size()) {
                if (a[j] == 0) cur++;
                else ans += cur/2, cur = 0;
            }
            ans += cur/2;
        }

        cout << ans << endl;
    } 
    
    return 0;
}
