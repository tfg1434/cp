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
// constexpr ll P = 998244353;

struct E {
    ll leave, arrive, v;
    bool operator < (E a) {
        return leave < a.leave;
    }
};

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n, m; while (cin >> n >> m) {
        vector<vector<E>> adj_inp(n+1), adj(n+1);
        vector<ll> a(n+1), bestTime(n+1, INFF);
        // bestTime[1] = 0;
        for (ll i = 0; i < m; i++) {
            ll u, leave, v, arrive; cin >> u >> leave >> v >> arrive;
            adj_inp[u].pb({leave, arrive, v});
        }
        for (ll i = 1; i <= n; i++) cin >> a[i]; 
        a[1] = 0;
        for (ll i = 1; i <= n; i++) {
            for (auto [leave, arrive, v] : adj_inp[i]) {
                adj[i].pb({ leave-a[i], arrive, v });
            }
            sort(rall(adj[i]));
        }
        vector<ll> pos(n+1);

        y_combinator([&](auto rec, ll u, ll newBestTime) -> void {
            ll oldBestTime = bestTime[u];
            newBestTime = min(newBestTime, bestTime[u]);
            bestTime[u] = newBestTime;
            while (pos[u] < adj[u].size()) {
                auto [leave, arrive, v] = adj[u][pos[u]];
                gg(leave, arrive, u, v, newBestTime, bestTime[u], oldBestTime);
                //departure time newBestTime <= d < oldBestTime;
                if (leave >= bestTime[u] && leave < oldBestTime) {
                    rec(v, arrive);
                } else {
                    break;
                }
                pos[u]++;
            }
        })(1, 0);

        for (ll i = 1; i <= n; i++) {
            cout << (bestTime[i] == INFF ? -1 : bestTime[i]) << endl;
        }
    } 
    
    return 0;
}
