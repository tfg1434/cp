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
constexpr ll mod = 1e9+7;
constexpr ll mod2 = 998244353;

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        ll n, m; cin >> n >> m;
        vector<vector<pll>> adj(n+1);
        vector<pll> e(m);
        string s(m, '0');
        for (ll i = 0; i < m; i++) {
            ll u, v; cin >> u >> v;
            adj[u].pb({v, i}); adj[v].pb({u, i});
            e[i] = {u, v};
        }
        
        vector<ll> vis(n+1, 0), lvl(n+1, 0), par(n+1, -1);
        y_combinator([&](auto rec, ll u) -> void {
            vis[u]=1;
            for (auto [v, idx] : adj[u]) {
                if (vis[v]) continue;
                lvl[v] = lvl[u]+1;
                par[v] = u;
                s[idx] = '1';
                rec(v);
            }
        })(1);
        map<ll, ll> cnt;
        for (ll i = 0; i < m; i++) {
            if (s[i] == '0') {
                cnt[e[i].first]++;
                cnt[e[i].second]++;
            }
        }
        
        if (cnt.size() == 3) {
            ll mn = INFF, mx = 0;
            for(auto [_,c]:cnt) {
                mn=min(mn,c);
                mx=max(mx,c);
            }
            if(mn==mx && mn==2) {
                vector<pll> can;
                for (auto [v, _]: cnt) {
                    can.pb({ lvl[v], v });
                }
                sort(all(can));
                ll u = can[0].second;
                ll i, j;
                for (auto [v, idx]:adj[u]) {
                    if (s[idx] == '0') i = idx;
                    else if (v == par[u]) j = idx;
                }

                s[i] = '1';
                s[j] = '0';
            }
        }
        
        cout << s << endl;
    } 
    
    return 0;
}

